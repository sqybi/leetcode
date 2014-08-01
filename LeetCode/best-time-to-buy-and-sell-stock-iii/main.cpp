#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int f[100000][3][2];
        int n = prices.size();
        if (n < 2)
        {
            return 0;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                f[0][i][j] = INT_MIN;
            }
        }
        f[0][0][0] = 0;
        f[0][1][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j != 0 && k == 1 && f[i - 1][j - 1][0] != INT_MIN)
                    {
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][0] - prices[i]);
                    }
                    if (k == 0 && f[i - 1][j][1] != INT_MIN)
                    {
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j][1] + prices[i]);
                    }
                }
            }
        }
        return max(f[n - 1][0][0], max(f[n - 1][1][0], f[n - 1][2][0]));
    }
};

int main()
{
    return 0;
}