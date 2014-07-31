#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *result = new ListNode(0);
        while (head != NULL)
        {
            ListNode *p = result;
            ListNode *temp = head->next;
            while (p->next != NULL)
            {
                if (p->next->val >= head->val)
                {
                    head->next = p->next;
                    p->next = head;
                    break;
                }
                p = p->next;
            }
            if (p->next == NULL)
            {
                p->next = head;
                head->next = NULL;
            }
            head = temp;
        }
        return result->next;
    }
};

void main()
{
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    head = solution.insertionSortList(head);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    getchar();
}