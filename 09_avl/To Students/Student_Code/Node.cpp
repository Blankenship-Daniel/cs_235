#include "Node.h"

Node::Node()
{
    data = 0;
    height = 0;
    balance = BALANCED;
    left = NULL;
    right = NULL;
}

Node::Node(int new_data)
{
    data = new_data;
    height = 0;
    balance = BALANCED;
    left = NULL;
    right = NULL;
}

Node::~Node()
{
    
}

int Node::getData()
{
    return data;
}

Node* Node::getLeftChild()
{
    return left;
}

Node* Node::getRightChild()
{
    return right;
}

void Node::setData(int data)
{
    this->data = data;
}

int Node::getHeight()
{
    height = findHeight();
    return (height > 0 ? height - 1 : 0);
}

// private functions
int Node::findHeight()
{
    int l = left ? left->findHeight() : 0;
    int r = right ? right->findHeight() : 0;
    return 1 + max(l, r);
}
