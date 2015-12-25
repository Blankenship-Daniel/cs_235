#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "PathfinderInterface.h"
#include "MazeLocation.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <stack>

class Pathfinder : public PathfinderInterface
{
    private:
        // private variables
        static const int X = 5;
        static const int Y = 5;
        static const int Z = 5;
        MazeLocation maze[X][Y][Z];
        vector<string> mazePath;
        stack<string> mazeStack;

        // private functions
        bool validMaze(string curr_maze);
        string formatMaze(string curr_maze);
        void setMaze(string curr_maze);
        void resetMaze();
        bool findMazePath(int x, int y, int z);

    public:
        // constructor
        Pathfinder();

        // public functions
        string getMaze();
        void createRandomMaze();
        bool importMaze(string file_name);
        vector<string> solveMaze();
        void printMaze();
};

#endif
