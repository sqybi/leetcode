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
    bool isValidBST(TreeNode *root) {
        return dfs(root, INT_MIN, INT_MAX);
    }

private:
    bool dfs(TreeNode *node, int lower, int upper)
    {
        if (node == NULL)
        {
            return true;
        }
        return node->val >= lower && node->val <= upper && dfs(node->left, lower, node->val - 1) && dfs(node->right, node->val + 1, upper);
    }
};

int main()
{
    return 0;
}