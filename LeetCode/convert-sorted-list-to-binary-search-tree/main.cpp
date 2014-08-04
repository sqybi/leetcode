#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Reference: http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == NULL)
		{
			return NULL;
		}
		int n = 0;
		auto node = head;
		while (node != NULL)
		{
			n++;
			node = node->next;
		}
		return dfs(head, 0, n - 1);
	}

private:
	TreeNode *dfs(ListNode *&node, int start, int end)
	{
		if (start > end)
		{
			return NULL;
		}
		int mid = (start + end) / 2;
		auto left = dfs(node, start, mid - 1);
		TreeNode *parent = new TreeNode(node->val);
		node = node->next;
		auto right = dfs(node, mid + 1, end);
		parent->left = left;
		parent->right = right;
		return parent;
	}
};

int main()
{
	return 0;
}