#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 0));
        while (!st.empty())
        {
            auto top = st.top();
            st.pop();
            auto node = top.first;
            if (node == NULL)
            {
                continue;
            }
            switch (top.second)
            {
            case 0:
                st.push(make_pair(node, 1));
                st.push(make_pair(node->left, 0));
                break;
            case 1:
                result.push_back(node->val);
                st.push(make_pair(node->right, 0));
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}