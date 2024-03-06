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
};
int DiameterOfTree(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int diam1 = DiameterOfTree(root->left);
    int diam2 = DiameterOfTree(root->right);
    int diam3 = HeightOfTree(root->left) + HeightOfTree(root->right) + 1;
    return max(diam3, max(diam1, diam2));
};
int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    node *root = tree.buildTree(nodes);
    int ans = DiameterOfTree(root);
    cout << ans;
    return 0;
}
