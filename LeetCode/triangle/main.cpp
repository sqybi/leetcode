#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        if (n == 0)
        {
            return 0;
        }
        int *dp = new int[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < i + 1; j++)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

int main()
{
    vector<vector<int>> triangle;
    vector<int> temp;
    temp.push_back(-10);
    triangle.push_back(temp);
    Solution solution;
    cout << solution.minimumTotal(triangle);
    getchar();
    return 0;
}