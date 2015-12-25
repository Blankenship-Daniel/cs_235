//
// Daniel Blankenship
// CS 235 Fall Midterm
//

#ifndef PERSON_H_
#define PERSON_H_

using namespace std;
#include <iostream>
#include <string>

class Person 
{
    private:
        string name;
        int strength;
        int speed;

    public:
        Person* next;
        Person* prev;

        Person();
        Person(string n, int str, int spd, Person* nxt, Person* prv);

        string getName();
        int getStrength();
        int getSpeed();
};

#endif
