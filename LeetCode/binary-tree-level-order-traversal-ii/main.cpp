#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		queue<pair<TreeNode*, int>> q;
		q.push(make_pair(root, 0));
		int level = 0;
		vector<vector<int>> result;
		if (root == NULL)
		{
			return result;
		}
		vector<int> temp;
		while (!q.empty())
		{
			auto node = q.front();
			q.pop();
			if (node.second > level)
			{
				result.push_back(temp);
				temp.clear();
				level = node.second;
			}
			temp.push_back(node.first->val);
			if (node.first->left != NULL)
			{
				q.push(make_pair(node.first->left, node.second + 1));
			}
			if (node.first->right != NULL)
			{
				q.push(make_pair(node.first->right, node.second + 1));
			}
		}
		if (temp.size() > 0)
		{
			result.push_back(temp);
		}
		vector<vector<int>> result2;
		for (auto it = result.rbegin(); it != result.rend(); it++)
		{
			result2.push_back(*it);
		}
		return result2;
	}
};

int main()
{
	return 0;
}