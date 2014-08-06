#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        n = s.length();
        memset(dp, 0xff, sizeof(dp));
        return decode(s, 0);
    }

private:
    int n;
    int dp[10000];

    int decode(string s, int k)
    {
        if (dp[k] == -1)
        {
            if (k >= n)
            {
                dp[k] = 0;
            }
            else if (k == n - 1)
            {
                dp[k] = s[k] != '0';
            }
            else if (k == n - 2)
            {
                dp[k] = s[k] != '0' && s[k + 1] != '0';
                dp[k] += s[k] == '1' || (s[k] == '2' && s[k + 1] <= '6');
            }
            else
            {
                dp[k] = 0;
                if (s[k] != '0')
                {
                    dp[k] = decode(s, k + 1);
                    if (s[k] == '1' || (s[k] == '2' && s[k + 1] <= '6'))
                    {
                        dp[k] += decode(s, k + 2);
                    }
                }
            }
        }
        return dp[k];
    }
};

int main()
{
    Solution solution;
    cout << solution.numDecodings("1");
    return 0;
}