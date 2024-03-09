#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{
    int idx = -1;

public:
    node *buildTree(int nodes[])
    {
        idx++;
        if (nodes[idx] == -1)
        {
            return nullptr;
        }
        node *newNode = new node(nodes[idx]);
        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);
        return newNode;
    }
};

node *searchBST(node *root, int val)
{
    
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == val)
        {
            return root;
        }
        else if (root->data > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
        return NULL;
    
}

int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    node *root = tree.buildTree(nodes);
    int a = 2;
    node *temp = searchBST(root, a);
    cout << temp->data;
    return 0;
}
