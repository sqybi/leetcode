#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL)
        {
            return head;
        }
        return sortList(head, NULL);
    }

private:
    ListNode *resultStart;
    ListNode *resultEnd;

    ListNode *sortList(ListNode *start, ListNode *end)
    {
        if (start->next == end)
        {
            return start;
        }
        int count = 0;
        ListNode *p = start;
        while (p != end)
        {
            count++;
            p = p->next;
        }
        count /= 2;
        ListNode *mid = start;
        for (int i = 0; i < count; i++)
        {
            mid = mid->next;
        }
        ListNode *p0 = sortList(start, mid);
        ListNode *p1 = sortList(mid, end);
        resultStart = NULL;
        resultEnd = NULL;
        while (p0 != mid || p1 != end)
        {
            if (p0 == mid)
            {
                AddToResult(p1);
                p1 = p1->next;
            }
            else if (p1 == end)
            {
                AddToResult(p0);
                p0 = p0->next;
            }
            else if (p0->val > p1->val)
            {
                AddToResult(p1);
                p1 = p1->next;
            }
            else
            {
                AddToResult(p0);
                p0 = p0->next;
            }
        }
        resultEnd->next = end;
        return resultStart;
    }

    void AddToResult(ListNode *p)
    {
        if (resultStart == NULL)
        {
            resultStart = p;
            resultEnd = p;
        }
        else
        {
            resultEnd->next = p;
            resultEnd = p;
        }
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
    head = solution.sortList(head);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    getchar();
}