#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        vector<int> a, s;
        int mins = INT_MAX;
        int minsi = -1;
        for (int i = 0; i < n; i++)
        {
            a.push_back(gas[i] - cost[i]);
            if (i == 0)
            {
                s.push_back(a[i]);
            }
            else
            {
                s.push_back(s[i - 1] + a[i]);
            }
            if (s[i] < mins)
            {
                mins = s[i];
                minsi = i;
            }
        }
        minsi++;
        int t = 0;
        for (int i = minsi; i < n; i++)
        {
            t += a[i];
            if (t < 0)
            {
                return -1;
            }
        }
        for (int i = 0; i < minsi; i++)
        {
            t += a[i];
            if (t < 0)
            {
                return -1;
            }
        }
        return minsi % n;
    }
};

int main()
{

    return 0;
}