/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "schedule.h"
#include "utils.h"
#include <algorithm>

/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string. 
 * 
 * Your V2D should match the exact structure of the input file -- so the first row, first column
 * in the original file should be the first row, first column of the V2D.
 *  
 * @param filename The filename of a CSV-formatted text file. 
 */
V2D file_to_V2D(const std::string & filename){
    // Your code here!
    V2D array;
    std::string file = file_to_string(filename);
    std::vector<std::string> rows;
    SplitString(file, '\n', rows);
    for (size_t i = 0; i < rows.size(); i++) {
        std::vector<std::string> columns;
        SplitString(rows[i], ',', columns);
        
        for (size_t j = 0; j < columns.size(); j++) {
            Trim(columns[j]);
            unsigned index = 0;
            char compare = ' ';
            //Trims the left white space
            while (index < columns[j].length() && columns[j][index] == compare) {
                index++;
            }
            columns[j] = columns[j].substr(index);
            index = 0;
            //Trims the right white space
            while (index < columns[j].length() && columns[j][index] != compare) {
                index++;
            }
            columns[j] = columns[j].substr(0,index);
        }
        array.push_back(columns);
    }
    return array;
}

/**
 * Given a course roster and a list of students and their courses, 
 * perform data correction and return a course roster of valid students (and only non-empty courses).
 * 
 * A 'valid student' is a student who is both in the course roster and the student's own listing contains the course
 * A course which has no students (or all students have been removed for not being valid) should be removed
 * 
 * @param cv A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param student A 2D vector of strings where each row is a student ID followed by the courses they are taking
 */
V2D clean(const V2D & cv, const V2D & student){
    // YOUR CODE HERE
    V2D array = cv;
    for (size_t i = 0; i < array.size(); i++) {
        std::string course = array[i][0];
        for (size_t j = 1; j < array[i].size(); j++) {
            std::string person = array[i][j];
            bool remove_student = true;
            for (size_t x = 0; x < student.size(); x++) {
                if (student[x][0] == person) {
                    for (size_t y = 0; y < student[x].size(); y++) {
                        if (student[x][y] == course) {
                            remove_student = false;
                        }
                    }
                }
            }
            if (remove_student) {
                array[i].erase(array[i].begin() + j);
                j--;
            }
        }
        if (array[i].size() == 1) {
            array.erase(array.begin() + i);
            i--;
        }
    }
    return array;
}

/**
 * Given a collection of courses and a list of available times, create a valid scheduling (if possible).
 * 
 * A 'valid schedule' should assign each course to a timeslot in such a way that there are no conflicts for exams
 * In other words, two courses who share a student should not share an exam time.
 * Your solution should try to minimize the total number of timeslots but should not exceed the timeslots given.
 * 
 * The output V2D should have one row for each timeslot, even if that timeslot is not used.
 * 
 * As the problem is NP-complete, your first scheduling might not result in a valid match. Your solution should 
 * continue to attempt different schedulings until 1) a valid scheduling is found or 2) you have exhausted all possible
 * starting positions. If no match is possible, return a V2D with one row with the string '-1' as the only value. 
 * 
 * @param courses A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param timeslots A vector of strings giving the total number of unique timeslots
 */
V2D schedule(const V2D &courses, const std::vector<std::string> &timeslots){
    Graph g = Graph(courses);
    
    int num_colors = timeslots.size();
    V2D array;
    for (size_t i = 0; i < timeslots.size(); i++) {
        std::vector<std::string> time;
        time.push_back(timeslots[i]);
        array.push_back(time);
    }
    bool valid = false;
    for (size_t i = 0; i < g.nodeList_.size(); i++) {
        unsigned counter = 0;
        bool possible = true;
        if (valid) {
            break;
        }
        for (size_t j = i; counter < g.nodeList_.size(); j++) {
            if (j == g.nodeList_.size()) {
                j = 0;
            }
            Graph::Node* current = g.nodeList_[j];
            if (current -> color == -1) { //if at an unlabeled vertex:
                for (int k = 0; k < num_colors; k++) { //code to find an available color
                    bool use = true;
                    for (Graph::Node* looper : current -> adjList) { //loop through all adjacent nodes to see if they use that color
                        if (k == looper -> color) {
                            use = false;
                            break;
                        }
                    }
                    if (use) {
                        current -> color = k;
                        break;
                    }
                    //if reach this line we can not use this color was found:
                    if (k == num_colors - 1) {
                        possible = false;
                    }
                }
                if (!(possible)) {
                    g.resetColors();
                    break;
                }
            } else { // otherwise continue:
                continue;
            }
            counter++;
            if (counter == g.nodeList_.size()) { //if we successfully colored all nodes
                valid = true;
            }   
        }
    }

    if (valid) {
        for (Graph::Node* looper : g.nodeList_) {
            int color = looper -> color;
            array[color].push_back(looper -> data);
        }
    } else {
        std::vector<std::string> empty{"-1"};
        std::vector<std::vector<std::string>> not_found;
        not_found.push_back(empty);
        return not_found;
    }
    return array;
}

Graph::Graph(V2D roster) {
    //Populates the node list:
    for (size_t i = 0; i < roster.size(); i++) {
        Node* node = new Node(roster[i][0]);
        for (size_t j = 1; j < roster[i].size(); j++) {
            node -> students.insert(roster[i][j]);
        }
        courses.insert(std::make_pair(roster[i][0], node));
        nodeList_.push_back(node);
    }

    //Populates the adjacency list:
    for (size_t i = 0; i < roster.size(); i++) {
        std::string course = roster[i][0];
        Node* node1 = courses[course];
        for (size_t j = 0; j < roster.size(); j++) {
            if (i == j) {
                continue;
            }
            Node* node2 = courses[roster[j][0]];
            for (size_t k = 1; k < roster[j].size(); k++) {
                if (node1 -> students.count(roster[j][k]) >= 1) {
                    insertEdge(node1, node2);
                }
            }
        }
    }
}

std::vector<std::string> Graph::incidentEdges(Node* v) {
    std::vector<std::string> adjacent;
    for (Node* node : v -> adjList) {
        adjacent.push_back(node -> data);
    }
    return adjacent;
}

bool Graph::areAdjacent(Node* v1, Node* v2) {
    for (Node* node : v1 -> adjList) {
        if (node -> data == v2 -> data) {
            return true;
        }
    }
    return false;
}

void Graph::insertEdge(Node* v1, Node* v2) {
    if (v1 -> adjList.count(v2) == 0) {
        v1->adjList.insert(v2);
    } 
}

void Graph::resetColors() {
    for (Node* looper : nodeList_) {
        looper -> color = -1;
    }
}   
