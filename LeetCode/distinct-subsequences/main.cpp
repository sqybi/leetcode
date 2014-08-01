#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// The problem statement actually means:
// ``The number of distinct subsequences of S equal to T''
class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.length();
        int m = T.length();
        if (n == 0 || m == 0 || n < m)
        {
            return 0;
        }
        vector<vector<int>> dp;
        for (int i = 0; i < n + 1; i++)
        {
            vector<int> temp(m + 1);
            dp.push_back(temp);
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= min(i, m); j++)
            {
                if (i > j)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (S[i - 1] == T[j - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution solution;
    cout << solution.numDistinct("babgbag", "bag");
    getchar();
    return 0;
}