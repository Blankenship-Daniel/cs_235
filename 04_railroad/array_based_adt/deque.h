#ifndef DEQUE_H_
#define DEQUE_H_

using namespace std;
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

template <typename T>
class Deque
{
private:
    // private variables
    static const size_t DEFAULT_CAPACITY = 10;
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    T* the_data;

    // private functions
    bool empty(void)
    {
        return (num_items == 0);
    }

    bool full(void)
    {
        return (num_items == capacity);
    }
 
    /*************************************
     * SHIFT ARRAY
     * shifts all elements in the array
     * to the right one position.
     ************************************/
    void shift_array()
    {
        T* new_data = new T[capacity];

        for (size_t i = 0; i < num_items; i++)
        {
            new_data[i+1] = the_data[i];          
        }

        swap(the_data, new_data);

        delete [] new_data;
    }

    /*************************************
     * REALLOCATE
     * if the array is full
     * double the capacity.
     ************************************/
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

public:

    // constructor
    Deque()    
    {
        capacity    = DEFAULT_CAPACITY;
        num_items   = 0;
        rear_index  = 0;
        front_index = 0;
        the_data    = new T[DEFAULT_CAPACITY];
    }
 
    // copy constructor
    Deque(const Deque<T> &rhs)
    {
        capacity    = rhs.capacity;
        num_items   = rhs.num_items;
        front_index = rhs.front_index;
        rear_index  = rhs.rear_index;
        the_data    = new T[rhs.capacity];
        
        for (size_t i = 0; i < capacity; i++)
        {
            the_data[i] = rhs.the_data[i];
        }
    }  

    // assignment operator
    Deque<T> & operator = (const Deque<T> &rhs)
    {
        if (this != &rhs)
        {   
            if (capacity != rhs.capacity)
            {
                delete [] the_data;
                the_data = new T[rhs.capacity];
            }
   
            for (size_t i = 0; i < rhs.capacity; i++)
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

    // destructor
    ~Deque(void)
    {
        delete [] the_data;
    }  
  
    /*************************************
     * PUSH RIGHT
     * adds an element to the right end
     * of an array.
     ************************************/
    void push_right(const T& item)
    {
        // --- check for overflow
        if (full())
        {
            reallocate();
        }
        the_data[rear_index] = item;
        rear_index = (rear_index + 1) % capacity;
        num_items++;
    }

    /*************************************
     * PUSH LEFT
     * adds an element to the left end
     * of an array.
     ************************************/
    void push_left(const T& item)
    {
        if (full())
        {
            reallocate();
        }
        if (front_index != 0)
        {
            front_index = (front_index - 1) % capacity;
            the_data[front_index] = item;
            num_items++;
            return;
        }
        if (!empty())
        {
            shift_array();
        }
        the_data[front_index] = item;
        rear_index = (rear_index + 1) % capacity;
        num_items++;
    }

    /*************************************
     * POP RIGHT
     * removes the right most element in
     * the array.
     ************************************/
    void pop_right()
    {
        if (empty())
        {
            cout << "Deque is empty.\n";
            front_index = 0;
            rear_index  = 0;
            return;
        }
        rear_index = (rear_index - 1) % capacity;
        num_items--;       
    }

    /*************************************
     * POP LEFT
     * removes the left most element in
     * the array.
     ************************************/
    void pop_left()
    {
        if (empty())
        {
            cout << "Deque is empty.\n";
            front_index = 0;
            rear_index  = 0;
            return;
        }
        front_index = (front_index + 1) % capacity;
        num_items--;
    }


    // return how large the deque is
    void size()
    { 
        cout << num_items << endl; 
    }

    // print out the contents of the deque
    void print()
    {
        for (int i = front_index; i <= rear_index; i++)
            cout << the_data[i] << " ";
        cout << endl;
    }
};

#endif
