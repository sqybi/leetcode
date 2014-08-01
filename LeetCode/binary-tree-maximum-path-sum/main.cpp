#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int singlePathSum, doublePathSum;
        dfs(root, singlePathSum, doublePathSum);
        return doublePathSum;
    }

private:
    void dfs(TreeNode *node, int &singlePathSum, int &doublePathSum)
    {
        if (node->left == NULL && node->right == NULL)
        {
            singlePathSum = node->val;
            doublePathSum = node->val;
            return;
        }

        int lSingle = 0, lDouble = INT_MIN, rSingle = 0, rDouble = INT_MIN;
        if (node->left != NULL)
        {
            dfs(node->left, lSingle, lDouble);
        }
        if (node->right != NULL)
        {
            dfs(node->right, rSingle, rDouble);
        }

        singlePathSum = max(max(lSingle, rSingle), 0) + node->val;
        doublePathSum = max(max(max(lDouble, rDouble), lSingle + rSingle + node->val), singlePathSum);
    }
};

int main()
{
    return 0;
}