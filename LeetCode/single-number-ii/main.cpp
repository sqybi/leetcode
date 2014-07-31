#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitCount[3];
        bitCount[0] = -1;
        bitCount[1] = 0;
        bitCount[2] = 0;
        for (int i = 0; i < n; i++)
        {
            int bitInc[3];
            for (int j = 0; j < 3; j++)
            {
                bitInc[j] = bitCount[j] & A[i];
            }
            for (int j = 0; j < 3; j++)
            {
                bitCount[j] ^= bitInc[j];
                bitCount[j] |= bitInc[(j + 2) % 3];
            }
        }
        return bitCount[1];
    }
};

int main()
{
    int A[] = { 1, 1, 1, 2, 2, 2, 4 };
    Solution solution;
    cout << solution.singleNumber(A, 7);
    getchar();

    return 0;
}