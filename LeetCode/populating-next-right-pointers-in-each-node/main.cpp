#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
        {
            return;
        }
        queue<pair<TreeLinkNode*, int>> q;
        q.push(make_pair(root, 0));
        TreeLinkNode *prev = NULL;
        int level = 0;
        while (!q.empty())
        {
            auto pair = q.front();
            q.pop();
            auto node = pair.first;
            auto l = pair.second;
            if (l != level)
            {
                prev->next = NULL;
                prev = NULL;
                level = l;
            }
            if (prev != NULL)
            {
                prev->next = node;
            }
            if (node->left != NULL)
            {
                q.push(make_pair(node->left, l + 1));
            }
            if (node->right != NULL)
            {
                q.push(make_pair(node->right, l + 1));
            }
            prev = node;
        }
    }
};

int main()
{
    return 0;
}