#ifndef NODE_H_
#define NODE_H_

#include <iostream>
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
        void setLeftChild(Node* left_node);
        void setRightChild(Node* right_node);
        void setData(int data);

        Node* left;
        Node* right;

    private:
        // private data members 
        int data;
};

#endif
