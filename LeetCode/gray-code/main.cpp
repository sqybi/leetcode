#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n == 0)
        {
            result.push_back(0);
            return result;
        }
        int m = 1 << n;
        for (int i = 0; i < m; i++)
        {
            result.push_back(getGrayCode(n, i));
        }
        return result;
    }

private:
    int getGrayCode(int n, int m)
    {
        int k = 1;
        bool *s = new bool[n];
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++)
        {
            int t = m % (k << 2);
            s[n - 1 - i] = (t >= k) && (t < k * 3);
            k <<= 1;
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = (result << 1) + s[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    solution.grayCode(1);
    return 0;
}