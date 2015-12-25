//
// Daniel Blankenship
// CS 235 Fall Midterm
//

#include "Deque.h"
#include <iostream>
using namespace std;

Deque::Deque()
{
    front = rear = NULL;
    count = 0;
}

Deque::~Deque()
{
    clear();
}

string Deque::getFrontName()
{
    return front->getName();
}

int Deque::getFrontStrength()
{
    return front->getStrength();
}

int Deque::getFrontSpeed()
{
    return front->getSpeed();
}

void Deque::insert_front(string name, int strength, int speed)
{
    front = new Person(name, strength, speed, front, NULL);
    if (front->next != NULL)
        front->next->prev = front;
    if (rear == NULL)
        rear = front;
    count++;
}

void Deque::remove_front()
{
    if (front == NULL)
    {
        cout << "Roster is empty...\n";
        return;
    }
    Person* removed_person = front;
    front = front->next;
    delete removed_person;
    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;
    count--;
}

void Deque::insert_back(string name, int strength, int speed)
{
    if (rear != NULL)
    {
        rear->next = new Person(name, strength, speed, NULL, rear);
        rear = rear->next;
        count++;
    }
    else 
    {
        insert_front(name, strength, speed);
    }
}

void Deque::remove_back()
{
    if (rear == NULL)
    {
        cout << "Roster is empty...\n";
        return;
    }
    Person* removed_person = rear;
    rear = rear->prev;
    delete removed_person;
    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;
    count--;
}

int Deque::size()
{
    return count;
}

bool Deque::isEmpty()
{
    return count == 0 ? true : false;
}

void Deque::clear()
{
    while (!isEmpty())
    {
        remove_front();
    }
    front = rear = NULL;
    count = 0;
}

void Deque::print()
{
    int i = 0;
    Person* traverse = front;

    while(traverse != NULL)
    {
        cout << "\t" << i << ". " << traverse->getName() << " "
             << "\t" << traverse->getStrength() << " "
             << "\t" << traverse->getSpeed() << endl;
        traverse = traverse->next;
        i++;
    }
    cout << "\tRoster Size: " << count << endl;
}

void Deque::printNames()
{
    Person* traverse = front;

    while(traverse != NULL)
    {
        if (traverse->next != NULL)
        {
            cout << traverse->getName() << ", ";
        }
        else
        {
            cout << traverse->getName() << endl;
        }
        traverse = traverse->next;
    }
}

void Deque::insert(string predecessor, string name, int strength, int speed)
{
    Person* curr = front;

    if (front == NULL)
    {
        insert_front(name, strength, speed);          
        return;
    }
    while(curr != NULL)
    {
        if (curr->getName() == predecessor)
        {
            break;
        }
        curr = curr->next;
    }
    if(rear == curr)
    {
        insert_back(name, strength, speed);
        return;
    }
    if(curr != NULL)
    {
        Person* newPerson = new Person(name, strength, speed, curr->next, curr); 
        curr->next->prev = newPerson;
        curr->next = newPerson;
    }
    else
    {
        cout << "\nPredecessor " << predecessor << " not found in list...\n";
        return;
    }
    count++;
}

void Deque::remove(string name)
{
    Person* curr = front;
    
    if (front == NULL)
    {
        cout << "\nRoster is empty...\n";
        return;
    }
    while(curr != NULL)
    {
        if (curr->getName() == name)
        {
            break;
        }
        curr = curr->next;
    }
    if (front == curr)
    {
        remove_front();
        return;
    }
    else if (rear == curr)
    {
        remove_back();
        return;
    }
    else 
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        count--;
    }
}

bool Deque::personExists(string name)
{
    Person* traverse = front;

    while (traverse != NULL)
    {
        if (traverse->getName() == name)
        {
            return true;
        }
        traverse = traverse->next;
    }
    return false;
}

int Deque::getCurrStrength(string name)
{
    Person* traverse = front;

    while (traverse != NULL)
    {
        if (traverse->getName() == name)
        {
            return traverse->getStrength();
        }
        traverse = traverse->next;
    }
    return -1;
}

int Deque::getCurrSpeed(string name)
{
    Person* traverse = front;

    while (traverse != NULL)
    {
        if (traverse->getName() == name)
        {
            return traverse->getSpeed();
        }
        traverse = traverse->next;
    }
    return -1;
}

string Deque::getNameAfter(string name)
{
    Person* traverse = front;

    while (traverse != NULL)
    {
        if (traverse->getName() == name && traverse->next != NULL)
        {
            return traverse->next->getName();
        }
        traverse = traverse->next;
    }
    return "NULL";
}

string Deque::getNameBefore(string name)
{
    Person* traverse = front;

    while (traverse != NULL)
    {
        if (traverse->getName() == name)
        {
            return traverse->prev->getName();
        }
        traverse = traverse->next;
    }
    return "NULL";
}
