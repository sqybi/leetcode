#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dup = NULL;
        auto node = head;
        head = NULL;
        ListNode *tail = NULL;
        bool flag = false;
        while (node != NULL)
        {
            auto next = node->next;
            if (dup == NULL)
            {
                dup = node;
                flag = true;
            }
            else
            {
                if (dup->val == node->val)
                {
                    flag = false;
                    delete dup;
                    dup = node;
                }
                else
                {
                    if (flag)
                    {
                        if (head == NULL)
                        {
                            head = dup;
                            tail = dup;
                        }
                        else
                        {
                            tail->next = dup;
                            tail = tail->next;
                        }
                    }
                    else
                    {
                        delete dup;
                    }
                    dup = node;
                    flag = true;
                }
            }
            node = next;
        }
        if (flag)
        {
            if (head == NULL)
            {
                head = dup;
                tail = dup;
            }
            else
            {
                tail->next = dup;
                tail = tail->next;
            }
        }
        else
        {
            delete dup;
        }
        if (head != NULL)
        {
            tail->next = NULL;
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    Solution solution;
    solution.deleteDuplicates(head);
    return 0;
}