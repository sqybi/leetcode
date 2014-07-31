#include <map>
#include <iostream>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) : capacity(capacity), count(0), head(NULL)
    {
    }

    int get(int key) {
        auto p = head;
        DataNode *prev = NULL;
        while (p != NULL)
        {
            if (p->key == key)
            {
                if (prev != NULL)
                {
                    prev->next = p->next;
                    p->next = head;
                    head = p;
                }
                return p->value;
            }
            prev = p;
            p = p->next;
        }
        return -1;
    }

    void set(int key, int value) {
        if (get(key) != -1)
        {
            head->value = value;
        }
        else
        {
            auto p = new DataNode(key, value);
            p->next = head;
            head = p;
            if (count < capacity)
            {
                count++;
            }
            else
            {
                while (p->next != NULL && p->next->next != NULL)
                {
                    p = p->next;
                }
                if (p->next != NULL)
                {
                    delete p->next;
                }
                p->next = NULL;
            }
        }
    }

private:
    struct DataNode
    {
        int key;
        int value;
        DataNode *next;
        DataNode(int x, int y) : key(x), value(y), next(NULL) {}
    };

    int capacity;
    int count;
    DataNode *head;
};

int main()
{
    LRUCache cache(1);
    cout << cache.get(0) << endl;
    cache.set(1, 2);
    cache.set(2, 3);
    cache.set(1, 3);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    getchar();

    return 0;
}