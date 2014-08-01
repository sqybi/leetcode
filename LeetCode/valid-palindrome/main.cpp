#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> a;
        for (char c : s)
        {
            c = tolower(c);
            if (isalnum(c))
            {
                a.push_back(c);
            }
        }
        int n = a.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (a[i] != a[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}