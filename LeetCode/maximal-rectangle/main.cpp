#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Solution: https://oj.leetcode.com/discuss/5198/a-o-n-2-solution-based-on-largest-rectangle-in-histogram
// Solution for single-dimension: http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        vector<vector<int>> s;
        int n = matrix.size();
        if (n == 0)
        {
            return 0;
        }
        int m = matrix[0].size();
        if (m == 0)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                int k = matrix[i][j] - '0';
                if (j == 0)
                {
                    temp.push_back(k);
                }
                else
                {
                    if (k == 0)
                    {
                        temp.push_back(0);
                    }
                    else
                    {
                        temp.push_back(temp[j - 1] + 1);
                    }
                }
            }
            s.push_back(temp);
        }
        int result = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                if (st.empty() || s[i][j] >= s[st.top()][j])
                {
                    st.push(i);
                }
                else
                {
                    while (!st.empty() && s[st.top()][j] > s[i][j])
                    {
                        int k = st.top();
                        st.pop();
                        int w;
                        if (!st.empty())
                        {
                            w = i - st.top() - 1;
                        }
                        else
                        {
                            w = i;
                        }
                        if (s[k][j] * w > result)
                        {
                            result = s[k][j] * w;
                        }
                    }
                    st.push(i);
                }
            }
            while (!st.empty())
            {
                int k = st.top();
                st.pop();
                int w;
                if (!st.empty())
                {
                    w = n - st.top() - 1;
                }
                else
                {
                    w = n;
                }
                if (s[k][j] * w > result)
                {
                    result = s[k][j] * w;
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}