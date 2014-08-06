#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        m--;
        n--;
        while (m >= 0 || n >= 0)
        {
            if (m < 0)
            {
                A[m + n + 1] = B[n];
                n--;
            }
            else if (n < 0)
            {
                A[m + n + 1] = A[m];
                m--;
            }
            else if (A[m] > B[n])
            {
                A[m + n + 1] = A[m];
                m--;
            }
            else
            {
                A[m + n + 1] = B[n];
                n--;
            }
        }
    }
};

int main()
{
    return 0;
}