#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string res = "";
        string temp = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (temp != "")
                {
                    if (res != "")
                    {
                        res.append(" ");
                    }
                    res.append(temp);
                    temp = "";
                }
            }
            else
            {
                temp = s[i] + temp;
            }
        }
        if (temp != "")
        {
            if (res != "")
            {
                res.append(" ");
            }
            res.append(temp);
        }
        s = res;
    }
};

void main()
{
    string s = "the sky is blue";
    Solution solution = Solution();
    solution.reverseWords(s);
    cout << s;
    cin >> s;
}