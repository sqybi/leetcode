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
        while (node != NULL)
        {
            auto next = node->next;
            if (dup == NULL || node->val != dup->val)
            {
                dup = node;
            }
            else
            {
                delete node;
                dup->next = next;
            }
            node = next;
        }
        return head;
    }
};

int main()
{
    return 0;
}