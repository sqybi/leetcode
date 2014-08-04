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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int pos = 0;
		return buildTree(inorder, preorder, 0, inorder.size(), pos);
	}

private:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int start, int end, int &pos)
	{
		if (start >= end)
		{
			return NULL;
		}
		int k;
		for (k = start; k < end; k++)
		{
			if (inorder[k] == preorder[pos])
			{
				break;
			}
		}
		TreeNode *node = new TreeNode(preorder[pos]);
		pos++;
		node->left = buildTree(inorder, preorder, start, k, pos);
		node->right = buildTree(inorder, preorder, k + 1, end, pos);
		return node;
	}
};

int main()
{
	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(2);
	vector<int> postorder;
	postorder.push_back(1);
	postorder.push_back(2);
	Solution solution;
	cout << solution.buildTree(inorder, postorder);
	getchar();
	return 0;
}