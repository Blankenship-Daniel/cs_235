#ifndef DEQUE_H_
#define DEQUE_H_

#include "Node.h"
#include <iostream>
using namespace std;

class Deque
{
    private:
        int count;
        Node* front;
        Node* rear;
        static const int MAX_CAP = 5;

    public:
        Deque();
        void push_left(int element);
        int  pop_left();
        void push_right(int element);
        int  pop_right();
        int  get_left();
        int  get_right();
        int  size();
        bool isEmpty();
        bool isFull();
        bool car_exists(int car);
        void print();
};

#endif
