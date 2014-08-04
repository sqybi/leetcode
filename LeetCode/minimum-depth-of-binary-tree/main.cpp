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
	int minDepth(TreeNode *root) {
		if (root == NULL)
		{
			return 0;
		}
		current = 0;
		result = INT_MAX;
		dfs(root);
		return result;
	}

private:
	int sum;
	int current;
	int result;

	void dfs(TreeNode *node)
	{
		if (node == NULL)
		{
			return;
		}
		current++;
		if (node->left == NULL && node->right == NULL && current < result)
		{
			result = current;
		}
		dfs(node->left);
		dfs(node->right);
		current--;
	}
};

int main()
{
	return 0;
}