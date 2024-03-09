#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // Base case: If the root is null, nothing to delete
        if (!root)
        {
            return nullptr;
        }

        // Recursive case
        if (root->val < key)
        {
            // The key to be deleted is in the right subtree
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key)
        {
            // The key to be deleted is in the left subtree
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // Node with the key to be deleted found

            if (!root->left)
            {
                // Case 1: Node with only right child or no child
                return root->right;
            }
            else if (!root->right)
            {
                // Case 2: Node with only left child
                return root->left;
            }

            // Case 3: Node with both left and right children
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }

            // Copy the inorder successor's value to this node
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

// Utility function to print the inorder traversal of the BST
void inorderTraversal(TreeNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution solution;
    int key = 3;
    std::cout << "Original BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Delete node with key
    root = solution.deleteNode(root, key);

    std::cout << "BST after deleting node with key " << key << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
