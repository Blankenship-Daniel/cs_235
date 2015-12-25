//
// Daniel Blankenship
// CS 235 Fall Midterm
//

#include "Person.h"

Person::Person()
{
    name = "";
    strength = 0;
    speed = 0;
    next = prev = NULL;
}

Person::Person(string n, int str, int spd, Person* nxt, Person* prv)
{
    name = n;
    strength = str;
    speed = spd;
    next = nxt;
    prev = prv;
}

string Person::getName()
{
    return name;
}

int Person::getStrength()
{
    return strength;
}

int Person::getSpeed()
{
    return speed;
}
