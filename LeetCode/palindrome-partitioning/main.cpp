#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.length();
        this->s = s;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < n - i + 1; j++)
            {
                if (i <= 1)
                {
                    isPalindrome[j][i] = true;
                }
                else
                {
                    isPalindrome[j][i] = isPalindrome[j + 1][i - 2] && s[j] == s[j + i - 1];
                }
            }
        }
        f(0);
        return result;
    }

private:
    vector<string> current;
    vector<vector<string>> result;
    string s;
    int n;
    bool isPalindrome[2000][2000];

    void f(int k)
    {
        if (k == n)
        {
            result.push_back(current);
            return;
        }
        for (int i = k + 1; i <= n; i++)
        {
            if (isPalindrome[k][i - k])
            {
                current.push_back(s.substr(k, i - k));
                f(i);
                current.pop_back();
            }
        }
    }
};

int main()
{
    Solution solution;
    auto result = solution.partition("aab");
    cout << result[0][0] << " " << result[0][1] << " " << result[0][2] << endl;
    cout << result[1][0] << " " << result[1][1] << endl;
    getchar();
    return 0;
}