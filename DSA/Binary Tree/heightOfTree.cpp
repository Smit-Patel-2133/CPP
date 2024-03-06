#include <iostream>
#include <math.h>
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
public:
    node *buildTree(int nodes[], int &idx)
    {
        idx++;
        if (nodes[idx] == -1)
        {
            return nullptr;
        }
        node *newNode = new node(nodes[idx]);
        newNode->left = buildTree(nodes, idx);
        newNode->right = buildTree(nodes, idx);
        return newNode;
    }
};

int HeightOfTree(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int LeftHeight = HeightOfTree(root->left);
    int RightHeight = HeightOfTree(root->right);
    int height = max(LeftHeight, RightHeight) + 1;
    return height;
}

int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    int idx = -1; // Initialize idx before passing it to buildTree
    node *root = tree.buildTree(nodes, idx);
    int ans = HeightOfTree(root);
    cout << ans;
    return 0;
}
