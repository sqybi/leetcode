#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        stack<pair<TreeNode*, int>> treeStack;
        treeStack.push(make_pair(root, 0));
        while (treeStack.size() != 0)
        {
            auto current = treeStack.top();
            if (current.second == 0)
            {
                current.second++;
                treeStack.pop();
                treeStack.push(current);
                // deal with left
                if (current.first->left != NULL)
                {
                    treeStack.push(make_pair(current.first->left, 0));
                }
            }
            else if (current.second == 1)
            {
                current.second++;
                treeStack.pop();
                treeStack.push(current);
                // deal with right
                if (current.first->right != NULL)
                {
                    treeStack.push(make_pair(current.first->right, 0));
                }
            }
            else
            {
                // add self
                result.push_back(current.first->val);
                treeStack.pop();
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    auto result = solution.postorderTraversal(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    getchar();

    return 0;
}