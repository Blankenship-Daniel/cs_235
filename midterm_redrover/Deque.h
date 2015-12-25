//
// Daniel Blankenship
// CS 235 Fall Midterm
//

#ifndef DEQUE_H_
#define DEQUE_H_

#include "Person.h"
#include <iostream>
using namespace std;

class Deque
{
    private:
        int count;
        Person* front;
        Person* rear;

    public:
        Deque();
        ~Deque();
        
        string getFrontName();
        int getFrontStrength();
        int getFrontSpeed();
        void insert_front(string name, int strength, int speed);
        void remove_front();
        void insert_back(string name, int strength, int speed);
        void remove_back();
        int size();
        bool isEmpty();
        void clear();
        void print();
        void printNames();
        void insert(string predecessor, string name, int strength, int speed);
        void remove(string name);
        bool personExists(string name);
        int getCurrStrength(string name);
        int getCurrSpeed(string name);
        string getNameAfter(string name);
        string getNameBefore(string name);
};

#endif
