/* Your code here! */

#include "maze.h"

SquareMaze::SquareMaze() {
    height_ = 0;
    width_ = 0;
}

void SquareMaze::makeMaze(int width, int height) {
    width_ = width;
    height_ = height;
    if (!(maze.empty())) {
        maze.erase(maze.begin());
    }
    std::vector<std::pair<bool,bool>> boolean;
    DisjointSets set;
    set.addelements(width*height);
    for (int w = 0; w < width; w++) {
        boolean.push_back(std::make_pair(true,true)); // construct each row of the maze, first bool is right wall, 
    }                                           // second bool is down wall
    for (int h = 0; h < height; h++) {
        maze.push_back(boolean);
    }

    int start_col = rand() % (width);
    int start_row = rand() % (height);
    while (set.size(start_row * width + start_col) < (width*height)) {
        int random_col = rand() % (width); 
        int random_row = rand() % (height);
        
        int random_wall = rand() % 2; // if 0, remove right wall. if 1, remove down wall

        int adjacent_col = random_col;
        int adjacent_row = random_row;
        if (random_wall == 0) { // remove right wall
            if (maze[random_row][random_col].first == false || random_col == width - 1) { // if the wall has already been removed or is a perimeter
                continue;
            } 
            adjacent_col++;
        } else { // remove down wall
            if (maze[random_row][random_col].second == false || random_row == height - 1) {
                continue;
            } 
            adjacent_row++;
        }

        if (set.find(random_row * width + random_col) != set.find(adjacent_row * width + adjacent_col)) { 
            set.setunion(random_row* width + random_col, adjacent_row* width + adjacent_col);
            setWall(random_col,random_row,random_wall,false);
        }
    }
}

bool SquareMaze::canTravel(int x, int y, int dir)const {
    if (dir == 0) { // move to the right +1 x
        if (x + 1 < width_) {
            return !(maze[y][x].first);
        } else {
            return false;
        }
    } else if (dir == 1) { //move down +1 y
        if (y + 1 < height_) {
            return !(maze[y][x].second);
        } else {
            return false;
        }
    } else if (dir == 2) { // move left -1 x
        if (x - 1 >= 0) {
            return !(maze[y][x - 1].first);
        } else {
            return false;
        }
    } else if (dir == 3) { 
        if (y - 1 >= 0) {
            return !(maze[y - 1][x].second);
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {
    if (dir == 0) { //sets the right wall to exist
        maze[y][x].first = exists;
    } else { // sets the down wall to exist
        maze[y][x].second = exists;
    }
}

std::vector<int> SquareMaze::solveMaze() {
    std::queue<std::pair<int,int>> queue;
    std::queue<int> row;
    std::set<std::pair<int,int>> visited;
    std::pair<int,int> solver = std::make_pair(0,0); // pair<row,col>
    std::vector<std::vector<int>> solved; //2d vector where each row is a possible solution, and each number is the direction traveled
    std::vector<std::vector<int>> bottom;
    std::vector<int> bottom_x;
    queue.push(solver);
    // visited.insert(solver);
    int counter = 0;
    bool first = true;
    while (!(queue.empty())) {
        solver = queue.front();
        queue.pop();
        visited.insert(solver);
        row.push(counter);

        if (canTravel(solver.second, solver.first, 0) && visited.count(std::make_pair(solver.first,solver.second + 1)) == 0) { // if we can travel to the right and it hasn't been visited
            queue.push(std::make_pair(solver.first, solver.second + 1));
            if (first == true) {
                std::vector<int> traverse{0};
                solved.push_back(traverse);
            } else {
                std::vector<int> traverse = solved[row.front()];
                traverse.push_back(0);
                solved.push_back(traverse);
            }
            if (solver.first == height_ - 1) {
                bottom.push_back(solved[solved.size() - 1]);
                bottom_x.push_back(solver.second + 1);
            }
        }  
        if (canTravel(solver.second, solver.first, 1) && visited.count(std::make_pair(solver.first + 1,solver.second)) == 0) { // if we can travel down
            queue.push(std::make_pair(solver.first + 1, solver.second));
            if (first == true) {
                std::vector<int> traverse{1};
                solved.push_back(traverse);
            } else {
                std::vector<int> traverse = solved[row.front()];
                traverse.push_back(1);
                solved.push_back(traverse);
            }
            if (solver.first + 1 == height_ - 1) {
                bottom.push_back(solved[solved.size() - 1]);
                bottom_x.push_back(solver.second);
            }
        } 
        if (canTravel(solver.second, solver.first, 2) && visited.count(std::make_pair(solver.first,solver.second - 1)) == 0) { // if we can travel left
            queue.push(std::make_pair(solver.first, solver.second - 1));
            if (first == true) {
                std::vector<int> traverse{2};
                solved.push_back(traverse);
            } else {
                std::vector<int> traverse = solved[row.front()];
                traverse.push_back(2);
                solved.push_back(traverse);
            }
            if (solver.first == height_ - 1) {
                bottom.push_back(solved[solved.size() - 1]);
                bottom_x.push_back(solver.second - 1);
            }
        } 
        if (canTravel(solver.second, solver.first, 3) && visited.count(std::make_pair(solver.first - 1,solver.second)) == 0) { // if we can travel up
            queue.push(std::make_pair(solver.first - 1, solver.second));
            if (first == true) {
                std::vector<int> traverse{3};
                solved.push_back(traverse);
            } else {
                std::vector<int> traverse = solved[row.front()];
                traverse.push_back(3);
                solved.push_back(traverse);
            }
        }   

        if (!first) {
            row.pop();
        }
        first = false;
        
        counter++;    
    }
    int max = 0;
    for (size_t i = 1; i < bottom.size(); i++) {
        if (bottom[i].size() > bottom[max].size()) {
            max = i;
        } else if (bottom[i].size() == bottom[max].size()) {
            if (bottom_x[i] < bottom_x[max]) {
                max = i;
            }
        }

    }
    return bottom[max];
}

PNG* SquareMaze::drawMaze() const {
    PNG* png = new PNG(width_ * 10 + 1, height_*10 + 1);
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            if (j == 0) {
                for (int k = 0; k < 10; k++) {
                    if (i * 10 + k < 1 || i * 10 + k > 9) {
                        png -> getPixel(i * 10  + k, 0).l = 0;
                    }
                }            
            }
            if (i == 0) {
                for (int k = 0; k < 10; k++) {
                    png -> getPixel(0, j * 10 +k).l = 0;
                } 
            }
            if (maze[j][i].first == true) { //right wall exists
                for (int k = 0; k <= 10; k++) {
                    png -> getPixel((i+1) * 10, j * 10 + k).l = 0;
                }
            }
            if (maze[j][i].second == true) {// bottom wall exists
                for (int k = 0; k <= 10; k++) {
                    png->getPixel(i*10 + k, (j+1)*10).l = 0;
                }
            }
        }
    }
    return png;
}

PNG* SquareMaze::drawMazeWithSolution() {
    PNG* image = drawMaze();
    std::vector<int> solution = solveMaze();
    
    int row = 5;
    int col = 5;

    for (size_t i = 0; i < solution.size(); i++) {
        if (solution[i] == 0) {
            for (int i = 0; i < 10; i++) {
                image->getPixel(col, row) = HSLAPixel(0,1,0.5,1); 
                col++;   
            }
        } else if (solution[i] == 1) {
            for (int i = 0; i < 10; i++) {
                image->getPixel(col, row) = HSLAPixel(0,1,0.5,1);
                row++;
            }
        } else if (solution[i] == 2) {
            for (int i = 0; i < 10; i++) {
                image->getPixel(col, row) = HSLAPixel(0,1,0.5,1);
                col--;
            }
            
        } else { // solution[i] == 3
            for (int i = 0; i < 10; i++) {
                image->getPixel(col, row) = HSLAPixel(0,1,0.5,1);
                row--;
            }
        }
    }
    image->getPixel(col,row) = HSLAPixel(0,1,0.5,1);
    col -= 4;

    for (int k = 0; k < 9; k++) {
        image->getPixel(col + k, height_ * 10).l = 1;
    }
    return image;
}