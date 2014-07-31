#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        length = s.length();
        memset(f, 0, sizeof(f));
        memset(d, 0, sizeof(d));
        return dp(0, s, dict);
    }

private:
    bool d[1000];
    bool f[1000];
    int length;

    bool dp(int k, string s, unordered_set<string> &dict)
    {
        if (f[k])
        {
            return d[k];
        }

        f[k] = true;

        if (k == length)
        {
            d[k] = true;
            return d[k];
        }

        for (auto iterator = dict.begin(); iterator != dict.end(); iterator++)
        {
            string word = *iterator;
            if (s.substr(k, word.length()) == word)
            {
                auto result = dp(k + word.length(), s, dict);
                if (result)
                {
                    d[k] = true;
                    break;
                }
            }
        }
        return d[k];
    }
};

int main()
{
    Solution solution;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    dict.insert("aaaaa");
    dict.insert("aaaaaa");
    dict.insert("aaaaaaa");
    dict.insert("aaaaaaaa");
    dict.insert("aaaaaaaaa");
    dict.insert("aaaaaaaaaa");

    cout << (int)solution.wordBreak(s, dict);

    getchar();

    return 0;
}