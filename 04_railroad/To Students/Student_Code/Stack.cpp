#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    top = NULL;
    num_items = 0;
}

void Stack::push(int element)
{
    if (isFull())
        return;

    Node* temp = new Node();
    temp->set_data(element);
    temp->set_next(NULL);
    temp->set_prev(NULL);

    if (isEmpty())
    {
        top = temp;
    }
    else
    {
        temp->set_next(top);
        top->set_prev(temp);
        top = temp;
    }
    num_items++;
}

int Stack::get_top()
{
    return top->get_data();
}

void Stack::pop()
{
    Node* old_top = top;
    top = top->get_next();
    delete old_top;
    num_items--;
}

bool Stack::isEmpty()
{
    return top == NULL;
}

bool Stack::isFull()
{
    return num_items == MAX_CAP;
}

bool Stack::car_exists(int car)
{
    Node* traverse = top;
    while(traverse != NULL)
    {
        if (traverse->get_data() == car)
            return true;
        traverse = traverse->get_next();
    }
    return false;
}

int Stack::size()
{
    return num_items;
}

void Stack::print()
{
    Node* traverse = top;
    while(traverse != NULL)
    {
        cout << traverse->get_data() << " ";
        traverse = traverse->get_next();
    }
    cout << endl;
}

