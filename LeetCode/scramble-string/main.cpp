#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != s2.length())
        {
            return false;
        }
        if (n == 1)
        {
            return s1 == s2;
        }
        multiset<char> set1;
        multiset<char> set2;
        multiset<char> set3;
        bool result = false;
        for (int i = 1; i < n; i++)
        {
            set1.insert(s1[i - 1]);
            set2.insert(s2[i - 1]);
            set3.insert(s2[n - i]);
            if (set1 == set2)
            {
                result = result || (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)));
            }
            if (set1 == set3)
            {
                result = result || (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)));
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}