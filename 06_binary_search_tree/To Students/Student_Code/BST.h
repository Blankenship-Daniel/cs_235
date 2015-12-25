#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "Node.h"
#include "BSTInterface.h"
#include <iomanip>
using namespace std;

class BinarySearchTree : public BSTInterface 
{   
    private:
        Node* rootNode;
        
        // private functions
        bool add(Node* local_root, int data);
        bool remove(Node*& local_root, int data);
        void replaceParent(Node*& old_root, Node*& local_root);
    
    public:
        // constructor
        BinarySearchTree();
        ~BinarySearchTree();

        // public functions -- implementing pure virtual
        //                      from BSTInterface
        Node* getRootNode();
        bool add(int data);
        bool remove(int data);

        // public functions
        void print(Node* local_root, int indent);
};

#endif
