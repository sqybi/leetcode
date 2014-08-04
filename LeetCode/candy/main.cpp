#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAXN 50000

class Solution {
public:
    int candy(vector<int> &ratings) {
        n = ratings.size();
        memset(head, 0xFF, sizeof(head));
        memset(dist, 0xFF, sizeof(head));
        memset(next, 0xFF, sizeof(head));
        memset(hasInDegree, 0, sizeof(hasInDegree));
        count = 0;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] < ratings[i - 1])
            {
                dist[count] = 1;
                next[count] = head[i];
                target[count] = i - 1;
                head[i] = count;
                hasInDegree[i - 1] = true;
                count++;
            }
            else if (ratings[i] > ratings[i - 1])
            {
                dist[count] = 1;
                next[count] = head[i - 1];
                target[count] = i;
                head[i - 1] = count;
                hasInDegree[i] = true;
                count++;
            }
        }
        memset(result, 0, sizeof(result));
        memset(inStack, 0, sizeof(inStack));
        for (int i = 0; i < n; i++)
        {
            if (!hasInDegree[i])
            {
                q.push(i);
                result[i] = 1;
                inStack[i] = true;
            }
        }
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            inStack[k] = false;
            int temp = head[k];
            while (temp != -1)
            {
                if (result[k] + dist[temp] > result[target[temp]])
                {
                    result[target[temp]] = result[k] + dist[temp];
                    if (!inStack[target[temp]])
                    {
                        q.push(target[temp]);
                        inStack[target[temp]] = true;
                    }
                }
                temp = next[temp];
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += result[i];
        }
        return total;
    }

private:
    int head[MAXN], dist[MAXN * 2], target[MAXN * 2], next[MAXN * 2];
    int n, count;
    int result[MAXN];
    bool hasInDegree[MAXN];
    bool inStack[MAXN];
    queue<int> q;
};

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    Solution solution;
    cout << solution.candy(a);
    getchar();

    return 0;
}