#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &set) {
        n = set.size() + 2;
        m = set.begin()->length();
        list.push_back(start);
        mapping[start] = 0;
        int k = 1;
        for (string s : set)
        {
            list.push_back(s);
            mapping[s] = k++;
        }
        list.push_back(end);
        mapping[end] = k;

        int q[10000];
        vector<int> depth;
        for (int i = 0; i < n; i++)
        {
            depth.push_back(0);
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            prev.push_back(temp);
        }
        depth[0] = 1;
        q[0] = 0;
        int qs = 0;
        int qe = 1;
        while (qs < qe && q[qs] != n - 1)
        {
            auto t = q[qs];
            qs++;
            for (int i = 0; i < m; i++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (list[t][i] != c)
                    {
                        string s = list[t];
                        s[i] = c;
                        if (mapping.find(s) != mapping.end())
                        {
                            int j = mapping[s];
                            if (depth[j] == 0)
                            {
                                depth[j] = depth[t] + 1;
                                q[qe++] = j;
                            }
                            if (depth[j] == depth[t] + 1)
                            {
                                prev[j].push_back(t);
                            }
                        }
                    }
                }
            }
        }
        goBack(n - 1);
        return result;
    }

private:
    vector<string> list;
    vector<string> current;
    vector<vector<string>> result;
    unordered_map<string, int> mapping;
    vector<vector<int>> prev;
    int n, m;

    void goBack(int k)
    {
        if (k == 0)
        {
            vector<string> temp;
            temp.push_back(list[0]);
            for (auto it = current.rbegin(); it != current.rend(); it++)
            {
                temp.push_back(*it);
            }
            result.push_back(temp);
            return;
        }
        current.push_back(list[k]);
        for (int i : prev[k])
        {
            goBack(i);
        }
        current.pop_back();
    }
};

int main()
{
    return 0;
}