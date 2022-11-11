/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        [](int c) {return std::ispunct(c);});
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        /* Your code goes here! */
        for (size_t j = 0; j < words.size(); j++) {
            if (file_word_maps[i].count(words[j]) == 0) {
                file_word_maps[i].insert(std::pair<string, unsigned int> (words[j],1));
            } else {
                file_word_maps[i][words[j]]++;
            }
        }
    }
}

void CommonWords::init_common()
{
    /* Your code goes here! */
    for (size_t i = 0; i < file_word_maps.size(); i++) {
        map<string, unsigned int> visited {};
        for (std::pair<string,unsigned int> pair : file_word_maps[i]) {
            if (common.count(pair.first) == 0 && visited.count(pair.first) == 0) {
                common.insert(std::pair<string,unsigned int> (pair.first,1));
                visited.insert(std::pair<string,unsigned int> (pair.first,1));
            } else if (visited.count(pair.first) == 0) {
                common[pair.first]++;
                visited.insert(std::pair<string,unsigned int> (pair.first, 1));
            }
        }
    }
}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    for (std::pair<string, unsigned int> looper : common) {
        if (looper.second != file_word_maps.size()) { // if the word doesn't appear in every file
            continue;
        } else { 
            for (size_t i = 0; i < file_word_maps.size(); i++) {
                if (file_word_maps[i].at(looper.first) >= n) {
                    if (i == file_word_maps.size() - 1) {
                        out.push_back(looper.first);
                    }
                } else {
                    break;
                }   
            }
        }
    }
    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}
