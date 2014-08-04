#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        this->n = n;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        return f(n);
    }

private:
    int n;
    int dp[10000];
    int f(int k)
    {
        if (dp[k] != 0)
        {
            return dp[k];
        }
        int result = 0;
        for (int i = 0; i < k; i++)
        {
            dp[k] += f(i) * f(k - i - 1);
        }
        return dp[k];
    }
};

int main()
{
    return 0;
}
