#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListInterface.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList : public LinkedListInterface<T> 
{
public:
    
    /*
     * CONSTRUCTOR
     * 
     */
    LinkedList()
	{
        listSize = 0;
        firstNode = NULL;
	}
    
    /*
     * DESTRUCTOR
     *
     */
    ~LinkedList()
	{
        clear();
	}

    /*
     * INSERT HEAD
     *
     */
    void insertHead(T value)
	{
        // creates a new Node with a value
        Node* newNode = new Node(value, NULL);

	    if (checkDuplicate(value))
		    return;

        // if the list is empty
        if (firstNode == NULL)
        {
            firstNode = newNode;
        }
        else // the list is not empty
        {
            newNode->next = firstNode;
            firstNode = newNode;
        }
        listSize++;
	}
    
    void printList()
    {
        Node* traverse;
        traverse = firstNode;

        while(traverse != NULL)
        {
            cout << traverse->data << endl;
            traverse = traverse->next;
        }
    }

    /*
     * INSERT TAIL
     *
     */
	void insertTail(T value)
	{
        Node* newNode = new Node(value, NULL);

	    if (checkDuplicate(value))
		    return;

        if (firstNode == NULL)
        {
            firstNode = newNode;    
        }
        else
        {
            Node* curr = firstNode;

            while(curr->next != NULL)
                curr = curr->next;

            curr->next = newNode;
        }
        listSize++;
	}

    /*
     * INSERT AFTER
     *
     */
    	void insertAfter(T value, T insertionNode)
	    {
        	Node* curr = firstNode;

		    if (checkDuplicate(value))
			    return;

        	while(curr != NULL && curr->data != insertionNode)
        	{
            		curr = curr->next;
        	}
        	curr->next = new Node(value, curr->next);
        	listSize++;
	}       

	bool checkDuplicate(T value)
	{
		Node* curr = firstNode;

		while(curr != NULL)
		{
			if (curr->data == value)
			{
				return true;
			}
			curr = curr->next;
		}
		return false;
	}	 
    /*
     * REMOVE
     *
     */
	void remove(T value)
	{
	    Node* delPtr = NULL;
        Node* trail  = firstNode;
        Node* curr   = firstNode;

	if (checkDuplicate(value) == false)
		return;

        while(curr != NULL && curr->data != value)
        {
            trail = curr;
            curr  = curr->next;
        }
        if(curr == NULL)
        {
            delete delPtr;
        }
        else
        {
            delPtr      = curr;
            curr        = curr->next;
            trail->next = curr;

            if (delPtr == firstNode)
            {
                firstNode = firstNode->next;
                trail     = NULL;
            }
            delete delPtr;
            listSize--;
        }
    }    
 
    /*
     * CLEAR
     *
     */
    void clear()
	{
        Node* temp_node = NULL; // temporary node

        // traverse the list
        while (firstNode != NULL)
        {
            temp_node = firstNode;
            firstNode = firstNode->next;
            delete temp_node;
        }
        firstNode = NULL;
	    listSize = 0;
	}

    /*
     * AT
     *
     */
    T at(int index)
	{
        	Node* curr   = firstNode; 
        	int position = 0;

        	if (index >= 0 && index < listSize)
        	{
            		while (position < index)
            		{
                		curr = curr->next;
                		position++;
            		}
            		return curr->data;
        	}
		else
		{
			return NULL;
		}
	}
        
    /*
     * SIZE
     *
     */
	int size()
	{
		return listSize;
	}

private:    
    /*
     * NODE
     *
     * creates a Node that contains data,
     *  and a pointer to the next element in
     *  a list.
     */
    struct Node
    {
        T data;
        Node* next;

        Node(const T& data_item, Node* next_ptr = NULL)
        {
            data = data_item;
            next = next_ptr;
        }
    };
       
    int listSize;    // size of the list
    Node* firstNode; // head of the list
};

#endif
