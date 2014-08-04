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
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL)
		{
			return false;
		}
		this->sum = sum;
		current = 0;
		return dfs(root);
	}

private:
	int sum;
	int current;

	bool dfs(TreeNode *node)
	{
		if (node == NULL)
		{
			return false;
		}
		current += node->val;
		bool result = (current == sum && node->left == NULL && node->right == NULL)
			|| dfs(node->left) || dfs(node->right);
		current -= node->val;
		return result;
	}
};

int main()
{
	return 0;
}