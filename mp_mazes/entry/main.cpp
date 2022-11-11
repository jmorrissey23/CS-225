#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    //cout << "Add your own tests here! Modify main.cpp" << endl;
    SquareMaze maze;
    maze.makeMaze(500,500);
    PNG * actualOutput = maze.drawMazeWithSolution();
    // std::cout << "Right: ";
    // std::cout <<  maze.canTravel(0,1,0) << std::endl;
    // std::cout << "Down: ";
    // std::cout << maze.canTravel(0,1,1) << std::endl;
    // std::cout << "Left: ";
    // std::cout << maze.canTravel(0,1,2) << std::endl;
    // std::cout << "Up: ";
    // std::cout << maze.canTravel(0,1,3) << std::endl;
    actualOutput->writeToFile("testMaze"+ string(".png"));

    vector<int> solve = maze.solveMaze();
    for (size_t i = 0; i < solve.size(); i++) {
        std::cout << std::to_string(solve[i]) + " ";
    }
    delete actualOutput;
    return 0;
}
