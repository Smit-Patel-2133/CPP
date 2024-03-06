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
int countNode(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftNode = countNode(root->left);
    int RightNode = countNode(root->right);
    return leftNode + RightNode + 1;
};
int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    node *root = tree.buildTree(nodes);
    int ans = countNode(root);
    cout << ans;
    return 0;
}
