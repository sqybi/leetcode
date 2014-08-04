#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Morris Traversal
// http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL;
        auto node = root;
        TreeNode *node1 = NULL;
        TreeNode *node2 = NULL;
        while (node != NULL)
        {
            if (!visited(node) && node->left != NULL)
            {
                node = node->left;
            }
            else
            {
                if (prev != NULL && prev->val > node->val)
                {
                    if (node1 == NULL)
                    {
                        node1 = prev;
                        node2 = node;
                    }
                    else
                    {
                        node2 = node;
                    }
                }
                prev = node;
                node = node->right;
            }
        }
        swap(node1->val, node2->val);
    }

private:
    bool visited(TreeNode *node)
    {
        if (node == NULL || node->left == NULL)
        {
            return false;
        }
        auto temp = node->left;
        while (temp->right != NULL)
        {
            if (temp->right == node)
            {
                temp->right = NULL;
                return true;
            }
            temp = temp->right;
        }
        temp->right = node;
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(20);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(-5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(14);
    root->right->right->left = new TreeNode(18);
    root->right->right->right = new TreeNode(25);

    /*TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);*/

    Solution solution;
    solution.recoverTree(root);
    getchar();
    return 0;
}