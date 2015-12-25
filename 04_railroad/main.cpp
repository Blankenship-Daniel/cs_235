#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include <iostream>
using namespace std;

int main()
{
    Stack s;
    Queue q;
    Deque d1, d2;

    for (int i = 1; i <= 10; i++)
    {
        s.push(i);
        q.push(i);
        d1.insert_front(i);
        d2.insert_back(i);
    }

    cout << "STACK RESULTS: " << endl;
    s.print();
    cout << "QUEUE RESULTS: " << endl;
    q.print();
    cout << "DEQUE INSERT FRONT: " << endl;
    d1.print();
    cout << "DEQUE INSERT BACK: " << endl;
    d2.print();

    return 0;
}
