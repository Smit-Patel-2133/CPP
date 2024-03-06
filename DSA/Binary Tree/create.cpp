#include <iostream>
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

int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 3, 4, -1, -1, 5, -1, -1, -1, 6, 7, -1, -1, 8, 9, -1, -1, 10, -1, -1};
    BinaryTree tree;
    node *root = tree.buildTree(nodes);
    // print
    cout << root->left->left->right->data << endl;

    return 0;
}
