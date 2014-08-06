#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        n = S.size();
        result.clear();
        current.clear();
        if (n == 0)
        {
            result.push_back(current);
            return result;
        }
        sort(S.begin(), S.end());
        vector<pair<int, int>> t;
        int k = S[0];
        int c = 1;
        for (int i = 1; i < n; i++)
        {
            if (S[i] == k)
            {
                c++;
            }
            else
            {
                t.push_back(make_pair(k, c));
                k = S[i];
                c = 1;
            }
        }
        t.push_back(make_pair(k, c));
        n = t.size();
        getSubsets(t, 0);
        return result;
    }

private:
    int n;
    vector<vector<int>> result;
    vector<int> current;

    void getSubsets(vector<pair<int, int>> &t, int k)
    {
        if (k == n)
        {
            result.push_back(current);
            return;
        }
        getSubsets(t, k + 1);
        for (int i = 0; i < t[k].second; i++)
        {
            current.push_back(t[k].first);
            getSubsets(t, k + 1);
        }
        for (int i = 0; i < t[k].second; i++)
        {
            current.pop_back();
        }
    }
};

int main()
{
    return 0;
}