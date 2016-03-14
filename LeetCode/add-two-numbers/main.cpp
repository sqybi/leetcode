#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr;
		ListNode* tail;
		int c = 0;
		while (l1 != nullptr && l2 != nullptr)
		{
			c += l1->val + l2->val;
			if (head == nullptr)
			{
				head = new ListNode(c % 10);
				tail = head;
			}
			else
			{
				tail->next = new ListNode(c % 10);
				tail = tail->next;
			}
			c /= 10;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1 == nullptr)
		{
			l1 = l2;
		}

		while (l1 != nullptr)
		{
			c += l1->val;
			if (head == nullptr)
			{
				head = new ListNode(c % 10);
				tail = head;
			}
			else
			{
				tail->next = new ListNode(c % 10);
				tail = tail->next;
			}
			c /= 10;
			l1 = l1->next;
		}

		if (c != 0)
		{
			tail->next = new ListNode(c);
		}

		return head;
	}
};

int main() {
	return 0;
}