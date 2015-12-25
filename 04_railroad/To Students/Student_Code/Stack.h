#ifndef STACK_H_
#define STACK_H_

#include "Node.h"
#include <iostream>
using namespace std;

class Stack
{
    private:
        Node* top;
        int num_items;
        static const int MAX_CAP = 5;

    public:
        Stack();
        void push(int element);
        int  get_top();
        void pop();
        bool isEmpty();
        bool isFull();
        bool car_exists(int car);
        int  size();
        void print();
};

#endif
