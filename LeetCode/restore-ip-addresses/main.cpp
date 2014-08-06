#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        n = s.length();
        vector<string> t;
        restore(s, 0, t);
        return result;
    }

private:
    vector<string> result;
    int n;

    void restore(string s, int k, vector<string> &t)
    {
        int m = t.size();
        if (k == n)
        {
            if (m == 4)
            {
                string res = t[0] + '.' + t[1] + '.' + t[2] + '.' + t[3];
                result.push_back(res);
            }
            return;
        }
        for (int i = 1; i <= 3; i++)
        {
            if (n - k - i < 4 - m - 1)
            {
                break;
            }
            if (n - k - i > (4 - m - 1) * 3)
            {
                continue;
            }
            string temp = s.substr(k, i);
            int num = atoi(temp.c_str());
            if (num < 256 && (i == 1 || temp[0] != '0'))
            {
                t.push_back(s.substr(k, i));
                restore(s, k + i, t);
                t.pop_back();
            }
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.restoreIpAddresses("010010")[0];
    return 0;
}