#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

class Node
{
    private:
        int data;
        Node* next;
        Node* prev;

    public:
        Node()
        {
            data = 0;
            next = prev = NULL;
        }

        int get_data()
        {
            return data;
        }

        void set_data(int data)
        {
            this->data = data;   
        }

        Node* get_next()
        {
            return next;
        }

        void set_next(Node* next)
        {
            this->next = next;
        }

        Node* get_prev()
        {
            return prev;
        }

        void set_prev(Node* prev)
        {
            this->prev = prev;
        }
};

#endif
