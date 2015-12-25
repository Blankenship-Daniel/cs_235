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
        void insert_front(int element);
        int  remove_front();
        void insert_back(int element);
        int  remove_back();
        int  get_front();
        int  get_back();
        int  size();
        bool isEmpty();
        bool isFull();
        void print();
};

#endif
