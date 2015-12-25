#include "Node.h"

Node::Node()
{
    data = 0;
    left = NULL;
    right = NULL;
}

Node::Node(int new_data)
{
    data = new_data;
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

void Node::setLeftChild(Node* left_node)
{
    left = left_node;
}

void Node::setRightChild(Node* right_node)
{
    right = right_node;
}

void Node::setData(int data)
{
    this->data = data;
}

