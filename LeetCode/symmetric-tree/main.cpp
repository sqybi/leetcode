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
	bool isSymmetric(TreeNode *root) {
		return check(root, root);
	}

private:
	bool check(TreeNode *lNode, TreeNode *rNode)
	{
		if (lNode == NULL && rNode == NULL)
		{
			return true;
		}
		if (lNode == NULL || rNode == NULL)
		{
			return false;
		}
		if (lNode->val != rNode->val)
		{
			return false;
		}
		return check(lNode->left, rNode->right) && check(lNode->right, rNode->left);
	}
};

int main()
{
	return 0;
}