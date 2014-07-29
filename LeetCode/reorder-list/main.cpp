#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		int length = 0;
		auto p = head;
		while (p != NULL)
		{
			length++;
			p = p->next;
		}
		if (length < 2)
		{
			return;
		}
		int halfLength = length - length / 2;
		
		auto halfHead = head;
		ListNode *prev = NULL;
		for (int i = 0; i < halfLength; i++)
		{
			prev = halfHead;
			halfHead = halfHead->next;
		}
		prev->next = NULL;

		p = halfHead->next;
		prev = halfHead;
		halfHead->next = NULL;
		while (p != NULL)
		{
			auto next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		halfHead = prev;

		p = head;
		while (p != NULL && halfHead != NULL)
		{
			auto pNext = p->next;
			auto halfHeadNext = halfHead->next;
			p->next = halfHead;
			halfHead->next = pNext;
			p = pNext;
			halfHead = halfHeadNext;
		}
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	Solution solution;
	solution.reorderList(head);
	while (head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	getchar();

	return 0;
}