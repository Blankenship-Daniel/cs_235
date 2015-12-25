#include "BST.h"

BinarySearchTree::BinarySearchTree()
{
    rootNode = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    while (rootNode != NULL)
    {
        remove(rootNode->getData());
    }
}

Node* BinarySearchTree::getRootNode()
{
    return rootNode;
}

// calls private function insert(Node* root, int data) recursively
bool BinarySearchTree::add(int data)
{
    if (this->rootNode == NULL)
    {
        rootNode = new Node(data);
        return true;
    }
    return add(this->rootNode, data);
}

bool BinarySearchTree::add(Node* local_root, int data)
{
    if (data < local_root->getData())
    {
        if (local_root->getLeftChild() == NULL)
        {
            local_root->setLeftChild(new Node(data));
            return true;
        }
        else 
        {
            return add(local_root->getLeftChild(), data);
        }
    }
    else if (data > local_root->getData())
    {
        if (local_root->getRightChild() == NULL)
        {
            local_root->setRightChild(new Node(data));
            return true;
        }
        else
        {
            return add(local_root->getRightChild(), data);
        }
    }
    else 
    {
        return false;
    }
}

bool BinarySearchTree::remove(int data)
{
    return remove(this->rootNode, data);
}

bool BinarySearchTree::remove(Node*& local_root, int data)
{
    if (local_root == NULL)
    {
        return false;
    }
    else
    {
        if (data < local_root->getData())
        {
            return remove(local_root->left, data);
        }
        else if (data > local_root->getData())
        {
            return remove(local_root->right, data);
        }
        else
        {
            Node* old_root = local_root;
            
            if (local_root->left == NULL)
            {
                local_root = local_root->right;
            }
            else if (local_root->right == NULL)
            {
                local_root = local_root->left;
            }
            else
            {
                replaceParent(old_root, old_root->left);
            }
            delete old_root;
            return true;
        }
    }
}

void BinarySearchTree::replaceParent(Node*& old_root, Node*& local_root)
{
    if (local_root->right != NULL)
    {
        replaceParent(old_root, local_root->right);
    }
    else
    {
        old_root->setData(local_root->getData());
        old_root = local_root;
        local_root = local_root->left;
    }
}

void BinarySearchTree::print(Node* local_root, int indent)
{
    if (local_root != NULL)
    {
        cout << local_root->getData() << endl;

        if (local_root->left)
        {
            cout << "LEFT CHILD " << endl;
            print(local_root->left,  indent + 4);
        }
        if (local_root->right)
        {
            cout << "RIGHT CHILD " << endl;
            print(local_root->right, indent + 4);
        }
    }
}
