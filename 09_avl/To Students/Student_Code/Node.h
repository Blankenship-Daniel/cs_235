#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <algorithm>
#include "NodeInterface.h"

class Node : public NodeInterface 
{    
    public:
        // constructors
        Node();
        Node(int new_data);
       
        // destructor
        ~Node();
    
        // public functions
        int getData();
        Node* getLeftChild();
        Node* getRightChild();
        void setData(int data);
        int getHeight();

        Node* left;
        Node* right;

        enum balance_type {LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = +1};
        balance_type balance;

    private:
        int data;
        int height;

        int findHeight();
};

#endif
