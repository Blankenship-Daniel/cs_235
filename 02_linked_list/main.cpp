#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> list;
    
    for (int i = 0; i < 20; i++)
    {
        list.insertTail(i);
    }
    list.printList();
    cout << endl;

    cout << list.at(0) << endl;

    return 0;
}
