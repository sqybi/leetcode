#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2)
        {
            return 0;
        }
        int result = 0;
        int minPrice = prices[0];
        for (int i = 1; i < n; i++)
        {
            minPrice = min(prices[i], minPrice);
            if (prices[i] - minPrice > result)
            {
                result = prices[i] - minPrice;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}