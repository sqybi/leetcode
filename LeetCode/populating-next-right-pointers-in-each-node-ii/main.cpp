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
        auto prevLevelHead = root;
        while (prevLevelHead != NULL)
        {
            TreeLinkNode *levelHead = NULL;
            TreeLinkNode *temp = NULL;
            while (prevLevelHead != NULL)
            {
                if (prevLevelHead->left != NULL)
                {
                    if (levelHead == NULL)
                    {
                        levelHead = prevLevelHead->left;
                    }
                    if (temp != NULL)
                    {
                        temp->next = prevLevelHead->left;
                    }
                    temp = prevLevelHead->left;
                }
                if (prevLevelHead->right != NULL)
                {
                    if (levelHead == NULL)
                    {
                        levelHead = prevLevelHead->right;
                    }
                    if (temp != NULL)
                    {
                        temp->next = prevLevelHead->right;
                    }
                    temp = prevLevelHead->right;
                }
                prevLevelHead = prevLevelHead->next;
            }
            prevLevelHead = levelHead;
        }
    }
};

int main()
{
    return 0;
}