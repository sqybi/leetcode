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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		int n = num.size();
		if (n == 0)
		{
			return NULL;
		}
		this->num = num;
		int position = 0;
		return dfs(position, 0, n - 1);
	}

private:
	vector<int> num;

	TreeNode *dfs(int &position, int start, int end)
	{
		if (start > end)
		{
			return NULL;
		}
		int mid = (start + end) / 2;
		auto left = dfs(position, start, mid - 1);
		TreeNode *parent = new TreeNode(num[position++]);
		auto right = dfs(position, mid + 1, end);
		parent->left = left;
		parent->right = right;
		return parent;
	}
};

int main()
{
	return 0;
}