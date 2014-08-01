#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp;
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back(result[i - 1][j] + result[i - 1][j - 1]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main()
{
    return 0;
}