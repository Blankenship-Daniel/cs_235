#ifndef STATION_H_
#define STATION_H_

#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "StationInterface.h"
#include <iostream>
using namespace std;

class Station : public StationInterface
{
    private:
        int curr_car;
        Stack station_stack;
        Queue station_queue;
        Deque station_deque;

    public:
        Station();

        // Part 1
        bool addToStation(int car);
        int  showCurrentCar();
        bool removeFromStation();

        // Part 2
        bool addToStack();
        bool removeFromStack();
        int  showTopOfStack();
        int  showSizeOfStack();

        // Part 3
        bool addToQueue();
        bool removeFromQueue();
        int  showTopOfQueue();
        int  showSizeOfQueue();

        // Part 4
        bool addToDequeLeft();
        bool addToDequeRight();
        bool removeFromDequeLeft();
        bool removeFromDequeRight();
        int  showTopOfDequeLeft();
        int  showTopOfDequeRight();
        int  showSizeOfDeque();
};

#endif
