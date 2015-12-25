#ifndef QUEUE_H_
#define QUEUE_H_

using namespace std;
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

/**********************************************************************
 * QUEUE : Class
 **********************************************************************/
template <typename T>
class Queue
{
private:
    static const size_t DEFAULT_CAPACITY = 10;
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    T* the_data;

public:

    /**********************************************************************
    * default constructor
    **********************************************************************/
    Queue()    
    {
        capacity    = DEFAULT_CAPACITY;
        num_items   = 0;
        front_index = 0;
        rear_index  = DEFAULT_CAPACITY - 1;
        the_data    = new T[DEFAULT_CAPACITY];
    }
 
    /***********************************************************************
    * Queue Copy Constructor
    ***********************************************************************/
    Queue(const Queue &rhs)
    {
        capacity    = rhs.capacity;
        num_items   = rhs.num_items;
        front_index = rhs.front_index;
        rear_index  = rhs.rear_index;
        the_data    = new T[rhs.capacity];
        
        for (int i = 0; i < capacity; i++)
        {
            the_data[i] = rhs.the_data[i];
        }
    }  
 
    /**********************************************************************
    * destructor
    **********************************************************************/
    ~Queue(void)
    {
        delete [] the_data;
    }  
 
    /***********************************************************************
    * Overloaded assignment operator.
    ***********************************************************************/
    Queue<T> & operator = (const Queue<T> &rhs)
    {
        if (this != &rhs)
        {   
            if (capacity != rhs.capacity)
            {
                delete [] the_data;
                the_data = new T[rhs.capacity];
            }
   
            for (int i = 0; i < rhs.capacity; i++)
            {
                the_data[i] = rhs.the_data[i];
            }
            capacity = rhs.capacity; 
            num_items = rhs.num_items; 
            front_index = rhs.front_index;
            rear_index  = rhs.rear_index;
        }
        return *this;
    }   

    /**********************************************************************
    * returns true if queue is empty
    **********************************************************************/
    bool empty(void)
    {
        return (num_items == 0);
    }

    /**********************************************************************
    * returns true if queue is full
    **********************************************************************/
    bool full(void)
    {
        return (num_items == capacity);
    }

    /**********************************************************************
    * inserts item into back of queue, then increments number of items
    * in queue
    **********************************************************************/
    void push(const T& item)
    {
        // --- check for overflow
        if (full())
        {
            reallocate();
        }
        num_items++;
        rear_index = (rear_index + 1) % capacity;
        the_data[rear_index] = item;
    }

    T& front()
    {
        return the_data[front_index];
    }

    const T& front() const 
    {
        return the_data[front_index];
    }

    /**********************************************************************
    * removes item from front of queue, then decrements number of items
    * in queue
    **********************************************************************/
    void pop()
    {
        front_index = (front_index + 1) % capacity;
        num_items--;
    }
  
    void reallocate()
    {
        size_t new_capacity = 2 * capacity;
        T* new_data         = new T[new_capacity];
        size_t j            = front_index;

        for (size_t i = 0; i < num_items; i++)
        {
            new_data[i] = the_data[j];
            j = (j + 1) % capacity;
        }
        
        front_index = 0;
        rear_index  = num_items - 1;
        capacity    = new_capacity;
        
        swap(the_data, new_data);

        delete [] new_data;
    }

    const int size() const
    { 
        return num_items; 
    }

    void print()
    {
        for (int i = front_index; i < num_items; i++)
            cout << the_data[i] << " ";
        cout << endl;
    }
};

#endif
