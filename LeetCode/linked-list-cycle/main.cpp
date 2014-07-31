#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return false;
		}
		auto slow = head;
		auto fast = head->next;
		while (slow != fast && fast->next != NULL && fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow == fast;
	}
};

int main()
{
	return 0;
}