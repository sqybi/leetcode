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
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		if (root == NULL)
		{
			return result;
		}
		this->sum = sum;
		current = 0;
		dfs(root);
		return result;
	}

private:
	int sum;
	int current;
	vector<vector<int>> result;
	vector<int> temp;

	void dfs(TreeNode *node)
	{
		if (node == NULL)
		{
			return;
		}
		current += node->val;
		temp.push_back(node->val);
		if (current == sum && node->left == NULL && node->right == NULL)
		{
			result.push_back(temp);
		}
		dfs(node->left);
		dfs(node->right);
		current -= node->val;
		temp.pop_back();
	}
};

int main()
{
	return 0;
}