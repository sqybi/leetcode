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
	void flatten(TreeNode *root) {
		if (root == NULL)
		{
			return;
		}
		prev = NULL;
		dfs(root);
		list.push_back(NULL);
		int n = list.size();
		for (int i = 0; i < n - 1; i++)
		{
			list[i]->left = NULL;
			list[i]->right = list[i + 1];
		}
	}

private:
	vector<TreeNode*> list;
	TreeNode* prev;

	void dfs(TreeNode *node)
	{
		if (node == NULL)
		{
			return;
		}
		list.push_back(node);
		dfs(node->left);
		dfs(node->right);
	}
};

int main()
{
	return 0;
}