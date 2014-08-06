#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
        auto node = head;
        while (node != NULL)
        {
            auto next = node->next;
            node->next = NULL;
            if (node->val < x)
            {
                if (tail1 == NULL)
                {
                    head1 = node;
                    tail1 = node;
                }
                else
                {
                    tail1->next = node;
                    tail1 = node;
                }
            }
            else
            {
                if (tail2 == NULL)
                {
                    head2 = node;
                    tail2 = node;
                }
                else
                {
                    tail2->next = node;
                    tail2 = node;
                }
            }
            node = next;
        }
        if (head1 == NULL)
        {
            return head2;
        }
        else
        {
            tail1->next = head2;
            return head1;
        }
    }
};

int main()
{
    return 0;
}