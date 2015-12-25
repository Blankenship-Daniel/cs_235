#include "Pathfinder.h"

#include <iostream>
using namespace std;

/******************************
 * MAIN 
 * a simple driver program.
 *****************************/
int main()
{
    Pathfinder p;

    p.createRandomMaze();
    p.solveMaze();
    p.printMaze();

    return 0;
}
