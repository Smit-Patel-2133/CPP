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
void InOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << "  ";
    InOrder(root->right);
};
int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    node *root = tree.buildTree(nodes);
    InOrder(root);
    // // print
    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->left->left->data << endl;
    // cout << root->left->right->data << endl;
    // cout << root->right->data << endl;
    // cout << root->right->right->data << endl;

    return 0;
}
