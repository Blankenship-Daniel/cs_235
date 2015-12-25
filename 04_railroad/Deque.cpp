#include "Deque.h"
#include <iostream>
using namespace std;

Deque::Deque()
{
    front = rear = NULL;
    count = 0;
}

void Deque::insert_front(int element)
{
    if (isFull())
        return;

    Node* temp = new Node();
    temp->set_data(element);
    temp->set_next(NULL);
    temp->set_prev(NULL);

    if (isEmpty())
    {
        front = rear = temp;
    }
    else
    {
        temp->set_next(front);
        front->set_prev(temp);
        front = temp;
    }

    count++;
}

int Deque::remove_front()
{
    if (isEmpty())
    {
        cout << "Deque is empty...\n";
        return -1;
    }
    
    int ret = front->get_data();

    Node* temp = front;
    if (front->get_next() != NULL)
    {
        front = front->get_next();
        front->set_prev(NULL);
    }
    else
    {
        front = NULL;
    }
    count--;
    delete temp;

    return ret;
}

void Deque::insert_back(int element)
{
    if (isFull())
        return;

    Node* temp = new Node();
    temp->set_data(element);
    temp->set_next(NULL);
    temp->set_prev(NULL);

    if (isEmpty())
    {
        front = rear = temp;
    }
    else
    {
        rear->set_next(temp);
        temp->set_prev(rear);
        rear = temp;
    }

    count++;
}

int Deque::remove_back()
{
    if (isEmpty())
    {
        cout << "Deque is empty...\n";
        return -1;
    }

    int ret = rear->get_data();

    Node* temp = rear;
    if (rear->get_prev() != NULL)
    {
        rear = rear->get_prev();
        rear->set_next(NULL);
    }
    else
    {
        rear = NULL;
    }
    count--;
    delete temp;

    return ret;
}

int Deque::get_front()
{
    if (isEmpty())
    {
        cout << "Deque is empty...\n";
        return -1;
    }

    return front->get_data();
}

int Deque::get_back()
{
    if (isEmpty())
    {
        cout << "Deque is empty...\n";
        return -1;
    }

    return rear->get_data();

}

int Deque::size()
{
    return count;
}

bool Deque::isEmpty()
{
    return count == 0 ? true : false;
}

bool Deque::isFull()
{
    return count == MAX_CAP;
}

void Deque::print()
{
    Node* traverse = front;
    while(traverse != NULL)
    {
        cout << traverse->get_data() << " ";
        traverse = traverse->get_next();
    }
    cout << endl;
}

