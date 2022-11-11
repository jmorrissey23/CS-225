/* Your code here! */

#pragma once

#include "dsets.h"
#include <cmath>
#include "cs225/PNG.h"
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace cs225;

class SquareMaze {
    public:
        SquareMaze();
        void makeMaze(int width, int height);
        bool canTravel(int x, int y, int dir)const;
        void setWall(int x, int y, int dir, bool exists);
        std::vector<int> solveMaze();
        PNG* drawMaze() const;
        PNG* drawMazeWithSolution();
    private:
        std::vector<std::vector<std::pair<bool,bool>>> maze; //std::pair<bool,bool> -- first bool is the right wall, second bool is the down wall
        int width_;
        int height_;
};