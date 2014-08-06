#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }

private:
    vector<TreeNode*> generate(int lower, int upper)
    {
        vector<TreeNode*> result;
        if (lower > upper)
        {
            result.push_back(NULL);
            return result;
        }
        for (int i = lower; i <= upper; i++)
        {
            auto leftTrees = generate(lower, i - 1);
            auto rightTrees = generate(i + 1, upper);
            for (auto leftTree : leftTrees)
            {
                for (auto rightTree : rightTrees)
                {
                    auto root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}