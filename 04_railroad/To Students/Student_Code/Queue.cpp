#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    num_items = 0;
    front = rear = NULL;
}

void Queue::push(int item)
{
    if (isFull())
        return;

    if (isEmpty())
    {
        rear = new Node();
        rear->set_data(item);
        rear->set_next(NULL);
        front = rear;
    }
    else
    {
        Node* temp = new Node();
        temp->set_data(item);
        temp->set_next(NULL);
        rear->set_next(temp);
        rear = rear->get_next();
    }
    num_items++;
}

int Queue::get_front()
{
    return front->get_data();
}

void Queue::pop()
{
    Node* old_front = front;
    front = front->get_next();
    if (front == NULL)
    {
        rear = NULL;
    }
    delete old_front;
    num_items--;
}

int Queue::size()
{
    return num_items;
}

bool Queue::isEmpty()
{
    return front == NULL;
}

bool Queue::isFull()
{
    return num_items == MAX_CAP;
}

bool Queue::car_exists(int car)
{
    Node* traverse = front;
    while (traverse != NULL)
    {
        if (traverse->get_data() == car)
            return true;
        traverse = traverse->get_next();
    }
    return false;
}

void Queue::print()
{
    Node *traverse = front;
    while (traverse != NULL)
    {
        cout << traverse->get_data() << " ";
        traverse = traverse->get_next();
    }
    cout << endl;
}
