#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result ^= A[i];
        }
        return result;
    }
};

int main()
{
    return 0;
}