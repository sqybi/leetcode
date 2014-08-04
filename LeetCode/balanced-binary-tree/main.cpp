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
	bool isBalanced(TreeNode *root) {
		if (root == NULL)
		{
			return true;
		}
		result = true;
		dfs(root);
		return result;
	}

private:
	bool result;

	int dfs(TreeNode *node)
	{
		if (node == NULL || !result)
		{
			return 0;
		}
		if (node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		int l = dfs(node->left);
		int r = dfs(node->right);
		if (abs(l - r) > 1)
		{
			result = false;
		}
		return max(l, r) + 1;
	}
};

int main()
{
	return 0;
}