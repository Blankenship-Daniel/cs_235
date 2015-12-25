//
// Daniel Blankenship
// CS 235 Fall Midterm
//

#ifndef REDROVER_H_
#define REDROVER_H_

#include "Deque.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

class RedRover
{
    private:
        Deque roster;
        Deque teamA;
        Deque teamB;

        void teamATurn(); // Handles logic for Team As turn
        void teamBTurn(); // Handles logic for Team Bs turn

    public:
        RedRover();
        ~RedRover();
        
        // Option 1
        bool createRoster(string filename);

        // Option 2
        void viewRoster();

        // Option 3
        void shuffleRoster();

        // Option 4
        void createTeams();

        // Option 5
        void viewTeams();

        // Option 6
        void userPlay();
};

#endif
