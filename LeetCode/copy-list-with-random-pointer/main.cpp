#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *result = NULL, *prev = NULL, *p = head, *temp;
        map<void*, void*> mapping;
        while (p != NULL)
        {
            temp = new RandomListNode(p->label);
            if (prev == NULL)
            {
                result = temp;
            }
            else
            {
                prev->next = temp;
            }
            mapping[p] = temp;
            p = p->next;
            prev = temp;
        }
        p = head;
        temp = result;
        while (p != NULL)
        {
            if (p->random != NULL)
            {
                temp->random = (RandomListNode*)mapping[p->random];
            }
            p = p->next;
            temp = temp->next;
        }
        return result;
    }
};

int main()
{
    RandomListNode *head = new RandomListNode(-1);
    head->next = new RandomListNode(1);
    head->next->random = head;
    Solution solution;

    auto result = solution.copyRandomList(head);
    cout << result->label;
    cout << result->next->label;
    cout << result->next->random->label;

    getchar();

    return 0;
}