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
int search(node *root, int max)
{
    if (!root)
        return 0;
    int count = 0;
    if (root->data >= max)
    {
        count++;
        max = root->data;
    }
    count += search(root->left, max);
    count += search(root->right, max);
    return count;
}
int goodNodes(node *root, int &max)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int goodNode = 1;
    goodNode += search(root->left, root->data);
    goodNode += search(root->right, root->data);
    return goodNode;
}

int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 1, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    node *root = tree.buildTree(nodes);
    int max = nodes[0];
    int a = goodNodes(root, max);
    cout << a;
    return 0;
}
