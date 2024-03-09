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

void LevelOrder(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *currNode = q.front();
        q.pop();

        if (currNode == nullptr)
        {
            cout << "";
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << currNode->data << " ";
            if (currNode->left != nullptr)
            {
                q.push(currNode->left);
            }

            if (currNode->right != nullptr)
            {
                q.push(currNode->right);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    node *root = tree.buildTree(nodes);
    LevelOrder(root);

    return 0;
}
