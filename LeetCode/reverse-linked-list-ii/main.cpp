#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        auto node = new ListNode(0);
        node->next = head;
        head = node;
        ListNode *p = NULL;
        ListNode *prev = NULL;
        for (int i = 0; i <= n; i++)
        {
            auto next = node->next;
            if (i == m - 1)
            {
                p = node;
            }
            if (i > m && i <= n)
            {
                node->next = prev;
            }
            if (i == n)
            {
                p->next->next = next;
                p->next = node;
            }
            prev = node;
            node = next;
        }
        return head->next;
    }
};