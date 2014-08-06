#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int result = 0;
        int n = height.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || height[i] >= height[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && height[st.top()] > height[i])
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
                    if (height[k] * w > result)
                    {
                        result = height[k] * w;
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
            if (height[k] * w > result)
            {
                result = height[k] * w;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}