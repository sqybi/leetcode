#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }
        dfs(root, 0);
        return result;
    }

private:
    int result;

    void dfs(TreeNode *node, int current)
    {
        current = current * 10 + node->val;
        if (node->left == NULL && node->right == NULL)
        {
            result += current;
            return;
        }
        if (node->left != NULL)
        {
            dfs(node->left, current);
        }
        if (node->right != NULL)
        {
            dfs(node->right, current);
        }
    }
};

int main()
{
    return 0;
}