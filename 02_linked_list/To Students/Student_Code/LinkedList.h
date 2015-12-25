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
     * sets listSize to 0
     * sets firstNode to NULL
     */
    LinkedList()
	{
        listSize = 0;
        firstNode = NULL;
	}
    
    /*
     * DESTRUCTOR
     *
     * calls the clear function to delete all pointers to Nodes
     */
    ~LinkedList()
	{
        clear();
	}

    /*
     * INSERT HEAD
     *
     * A node with the given value should be inserted at the 
     *  beginning of the list.
     *
     *  Do not allow duplicate values.
     */
    void insertHead(T value)
	{
        // creates a new Node with a value
        
	    if (checkDuplicate(value))
		    return;
        
        Node* newNode = new Node(value, NULL);

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
   
    /*
     * PRINT LIST
     *
     * For testing purposes only. 
     *  Displays what is in the current list.
     */
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
     * A node with the given value should be inserted at the 
     *  end of the list.
     *
     *  Do not allow duplicate values in the list.
     */
	void insertTail(T value)
	{
	    if (checkDuplicate(value))
		    return;
        
        Node* newNode = new Node(value, NULL);

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
     * A node with the given value should be inserted immediately after
     *  the node whose value is equal to insertionNode.
     *
     *  A node should only be added if the node whose value is equal to
     *   insertionNode. Do not allow duplicate values in the list.
     */
    void insertAfter(T value, T insertionNode)
	{
        /** if value already exists in the list return.
         *   if insertionNode does not exist in the list return. */
		if (checkDuplicate(value) || !checkDuplicate(insertionNode))
			return;

        /** if the list is not empty find insertionNode in the 
         *   list and insert newNode after. */
        if (firstNode != NULL)
        {
            Node* curr = firstNode;

       	    while(curr->next != NULL && curr->data != insertionNode)
       	    {
          	    curr = curr->next;
       	    }
            curr->next = new Node(value, curr->next);
            listSize++;
        }
        else
        {
            firstNode = new Node(value, NULL);
        }
	}       

    /*
     * CHECK DUPLICATE
     *
     * checks to see if a node with the given value exists in the list.
     *
     * returns true if duplicate is found. returns false otherwise.
     */
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
     * The node with the given value should be removed from the list.
     *
     * The list may or may not include a node with the given value.
     */
	void remove(T value)
	{
        if (!checkDuplicate(value) || firstNode == NULL)
            return;

        Node *pPre = NULL, *pDel = NULL;

        if (firstNode->data == value)
        {
            pDel = firstNode;
            firstNode = pDel->next;
            delete pDel;
            listSize--;
            return;
        }

        pPre = firstNode;
        pDel = firstNode->next;

        while (pDel != NULL)
        {
            if(pDel->data == value)
            {
                pPre->next = pDel->next;
                delete pDel;
                listSize--;
                break;
            }
            pPre = pDel;
            pDel = pDel->next;
        }
    }    
 
    /*
     * CLEAR
     *
     * Remove all nodes from the list.
     */
    void clear()
	{
        while (firstNode != NULL)
        {
            remove(firstNode->data);
        }
	}

    /*
     * AT
     *
     * Returns the value of the node at the given index. The list
     *  begins at index 0.
     *
     *  If the given index is out of range of the list, return NULL
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
     * returns the number of nodes in the list.
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
