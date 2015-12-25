#include "AVL.h"

AVL::AVL()
{
    increase = false;
    decrease = false;
    rootNode = NULL;
}

AVL::~AVL()
{
    while (rootNode != NULL)
    {
        remove(rootNode->getData());
    }
}

Node* AVL::getRootNode()
{
    return rootNode;
}

// calls private function insert(Node* root, int data) recursively
bool AVL::add(int data)
{
    bool return_value = add(rootNode, data);
    return return_value;
}

bool AVL::add(Node*& local_root, int data)
{
    if (local_root == NULL)
    {
        local_root = new Node(data);
        increase = true;
        return true;
    }
    else if (data < local_root->getData())
    {
        bool return_value = add(local_root->left, data);
        if (increase)
        {
            if (findBalance(local_root) == -2)
            {
                rebalanceLeft(local_root);
                increase = false;
            }
            else if (findBalance(local_root) == 0)
                increase = false;
        }
        return return_value;
    }
    else if (data > local_root->getData())
    {
        bool return_value = add(local_root->right, data);
        if (increase)
        {
            if (findBalance(local_root) == 2)
            {
                rebalanceRight(local_root);
                increase = false;
            }
            else if (findBalance(local_root) == 0)
                increase = false;
        }
        return return_value;
    }
    else
    {
        increase = false;
        return false;
    }
}

bool AVL::remove(int data)
{
    bool return_value = remove(this->rootNode, data);
    if (findBalance(rootNode) == 2)
    {
        rebalanceRight(rootNode);
    }
    if (findBalance(rootNode) == -2)
    {
        rebalanceLeft(rootNode);
    }
    return return_value;

}

bool AVL::remove(Node*& local_root, int data)
{
    if (local_root == NULL)
    {
        return false;
    }
    else
    {
        if (data < local_root->getData())
        {
            bool return_value = remove(local_root->left, data);
            balanceTree(local_root);
            return return_value;
        }
        else if (data > local_root->getData())
        {
            bool return_value = remove(local_root->right, data);
            balanceTree(local_root);
            return return_value;
        }
        else
        {
            Node* old_root = local_root;
            
            if (local_root->left == NULL)
                local_root = local_root->right;
            else if (local_root->right == NULL)
                local_root = local_root->left;
            else
                replaceParent(old_root, old_root->left);
            
            delete old_root;
            balanceTree(local_root);
            return true;
        }
    }
}

void AVL::balanceTree(Node*& local_root)
{
    if (local_root == NULL)
        return;
    
    if (findBalance(local_root) == 2)
        rebalanceRight(local_root);
    
    if (findBalance(local_root) == -2)
        rebalanceLeft(local_root);
    
    balanceTree(local_root->left);
    balanceTree(local_root->right);
}

void AVL::replaceParent(Node*& old_root, Node*& local_root)
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

void AVL::print(Node* local_root)
{
    if (local_root != NULL) {
        cout << local_root->getData() << " HEIGHT: " << local_root->getHeight() << endl;
        if (local_root->left)
        {
            cout << "L ";
            print(local_root->left);
        }
        if (local_root->right) 
        {
            cout << "R ";
            print(local_root->right);
        }
    }
}

// balancing functions
int AVL::height(Node* local_root)
{
    if (local_root == NULL)
    {
        return -1;
    }
    return local_root->getHeight();
}

int AVL::findBalance(Node* local_root)
{
    if (local_root == NULL)
    {
        return 0;
    }
    return (height(local_root->right) - height(local_root->left));
}

void AVL::rotateRight(Node*& local_root)
{
    Node* temp = local_root->left;
    local_root->left = temp->right;
    temp->right = local_root;
    local_root = temp;
}

void AVL::rotateLeft(Node*& local_root)
{
    Node* temp = local_root->right;
    local_root->right = temp->left;
    temp->left = local_root;
    local_root = temp;
}

void AVL::rebalanceLeft(Node*& local_root)
{
    if (findBalance(local_root->left) == 1)
        rotateLeft(local_root->left);
    rotateRight(local_root);
}

void AVL::rebalanceRight(Node*& local_root)
{
    if (findBalance(local_root->right) == -1)
        rotateRight(local_root->right);
    rotateLeft(local_root);
}
