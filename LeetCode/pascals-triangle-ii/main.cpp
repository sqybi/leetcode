#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> result(rowIndex);
        for (int i = 0; i < rowIndex; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (j == 0 || j == i)
                {
                    result[j] = 1;
                }
                else
                {
                    result[j] += result[j - 1];
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