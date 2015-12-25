#ifndef QUEUE_H_
#define QUEUE_H_

#include "Node.h"
#include <iostream>
using namespace std;

class Queue
{
    private:
        Node* front;
        Node* rear;
        int num_items;
        static const int MAX_CAP = 5;

    public:
        Queue();
        void push(int item);
        int  get_front();
        void pop();
        int  size();
        bool isEmpty();
        bool isFull();
        void print();
};

#endif
