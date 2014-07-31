#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        length = s.length();
        memset(f, 0, sizeof(f));
        auto result = dp(0, s, dict);
        for (auto iterator = result.begin(); iterator != result.end(); iterator++)
        {
            (*iterator) = iterator->substr(0, iterator->length() - 1);
        }
        return result;
    }

private:
    vector<string> d[1000];
    bool f[1000];
    int length;

    vector<string> dp(int k, string s, unordered_set<string> &dict)
    {
        if (f[k])
        {
            return d[k];
        }

        f[k] = true;

        if (k == length)
        {
            d[k].push_back("");
            return d[k];
        }

        for (auto iterator = dict.begin(); iterator != dict.end(); iterator++)
        {
            string word = *iterator;
            if (s.substr(k, word.length()) == word)
            {
                auto result = dp(k + word.length(), s, dict);
                for (auto resultIterator = result.begin(); resultIterator != result.end(); resultIterator++)
                {
                    d[k].push_back(word + " " + (*resultIterator));
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

    auto result = solution.wordBreak(s, dict);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    //cout << (int)solution.wordBreak(s, dict);

    getchar();

    return 0;
}