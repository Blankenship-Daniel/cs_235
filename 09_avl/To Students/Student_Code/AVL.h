#ifndef AVL_H_
#define AVL_H_

#include "Node.h"
#include "AVLInterface.h"
#include <iomanip>
using namespace std;

class AVL : public AVLInterface 
{   
    private:
        Node* rootNode;
        bool increase;
        bool decrease;
        
        bool add(Node*& local_root, int data);
        bool remove(Node*& local_root, int data);
        void replaceParent(Node*& old_root, Node*& local_root);
        void rotateRight(Node*& local_root);
        void rotateLeft(Node*& local_root);
        void rebalanceLeft(Node*& local_root);
        void rebalanceRight(Node*& local_root);
        int height(Node* local_root);
        int findBalance(Node* local_root);
        void balanceTree(Node*& local_root);

    public:
        AVL();
        ~AVL();

        Node* getRootNode();
        bool add(int data);
        bool remove(int data);
        void print(Node* local_root);
};

#endif
