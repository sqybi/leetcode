#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return NULL;
		}
		auto slow = head;
		auto fast = head->next;
		while (slow != fast && fast->next != NULL && fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		if (slow != fast)
		{
			return NULL;
		}
		int prevCount;
		int count = countNode(head, slow);
		do
		{
			slow = slow->next;
			prevCount = count;
			count = countNode(head, slow);
		} while (count > prevCount);
		return slow;
	}

private:
	int countNode(ListNode *start, ListNode *end)
	{
		int count = 0;
		while (start != end)
		{
			count++;
			start = start->next;
		}
		return count;
	}
};

int main()
{
	ListNode *head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = head->next;

	Solution solution;
	cout << solution.detectCycle(head)->val;
	getchar();

	return 0;
}