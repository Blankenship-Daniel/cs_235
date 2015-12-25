/************************************************************
*
*  NAME: Daniel Blankenship
*  AUTHOR: Bro. Ercanbrack
*  ASSIGN: Assignment 02
*  PROGRAM: stack.h
*  PURPOSE: Class definition for a stack object
*
************************************************************/
#ifndef STACK_H
#define STACK_H

using namespace std;
#include <iostream>
#include <cstdlib>

class Stack
{
   private:
     int myTop;                  // index of top of stack
     int maxSize;                // maximum size of stack  
     int *stackItems;            // pointer for dynamic array
   public:
     Stack(int size = 100);      // default constructor (stack size 100)
     Stack(const Stack & aStack); // copy constructor 
     ~Stack() {delete [] stackItems;};
     int top(void);              // returns the value of top item in the stack
     void push(int item);        // store item on the stack
     void pop(void);             // remove/delete top item off stack
     bool empty(void);           // is stack empty
     bool full(void);            // is stack full

     Stack& operator = (const Stack & rtSide); // overloaded assignment operator
};

/************************************************************
* STACK :: STACK
* Default constructor (stack size 100)
************************************************************/
Stack::Stack(int size)
{ 
   maxSize = size; // maxSize is initialized to 100
   myTop = 0;      // myTop is initialized to 0
   stackItems = new int[maxSize]; // initialized to 100 
}

/************************************************************
* STACK :: STACK
* Copy constructor
************************************************************/
Stack::Stack(const Stack & aStack)
{
   maxSize = aStack.maxSize; // make a copy of maxSize (100)
   myTop = aStack.myTop;     // make a copy of myTop   ( 0 )
   stackItems = new int[maxSize]; // make a copy of stackItems[100]

   // copy the contents of stackItems
   for (int i = 0; i < myTop; i++)
   {
      stackItems[i] = aStack.stackItems[i];
   }
}

/************************************************************
* STACK :: TOP
* Returns the value of top item in the stack
************************************************************/
int Stack::top(void)
{
   // checks to see if the stack is not empty
   //  if the stack is not empty it returns the
   //  value of the top element in the array
   if ( !empty() )
   {
      return stackItems[myTop - 1];
   }
   else // if empty gives error message
   {
      cout << "ERROR: Stack Underflow\n";
      return -1;
   }
}

/************************************************************
* STACK :: PUSH
* Store item on the stack
************************************************************/
void Stack::push(int item)
{
   // if the array still has space
   //  add the item to the stack and increment
   //  the counter by 1
   if (myTop < maxSize)
   {
      stackItems[myTop] = item;
      myTop++;
   }
   else // if the stack is full throw error message...
   {
      cout << "ERROR: Stack Overflow\n";
      exit(1); //...and exit the program
   }   
}

/************************************************************
* STACK :: POP
* Remove/delete top item off stack
************************************************************/
void Stack::pop(void)
{
   // if the stack is not empty
   //  remove the top item off of
   //  the stack
   if ( !empty() )
      myTop--;      
   else // if the stack is full throw error message...
   {
      cout << "ERROR: Stack Underflow\n";
      exit(1); // ...and exit the program
   }
}

/************************************************************
* STACK :: EMPTY
* Checks to see if the stack is empty
************************************************************/
bool Stack::empty(void)
{
   return (myTop == 0);
}

/************************************************************
* STACK :: FULL
* Checks to see if the stack if full
************************************************************/
bool Stack::full(void)
{
   return (myTop == maxSize);
}

/************************************************************
* STACK :: OPERATOR =
* Assigns right side to the left
************************************************************/
Stack & Stack::operator = (const Stack & rtSide)
{
   // if the maxSize of the left object is smaller
   //  than the size of the right object's maxSize...
   if (maxSize < rtSide.maxSize)
   {
      delete [] stackItems;     //...delete the contents of left stack
      maxSize = rtSide.maxSize; // copy the maxSize
      myTop = rtSide.myTop;     // copy the myTop
      stackItems = new int [maxSize]; // create a new dynamic array    
   }

   // copy the myTop so that the correct amount of data
   //  is passed
   myTop = rtSide.myTop;  

   // copy the contents of the dynamic array
   for (int i = 0; i < myTop; i++)
      stackItems[i] = rtSide.stackItems[i];
}

#endif
