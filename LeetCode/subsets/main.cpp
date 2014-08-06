#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &S) {
        n = S.size();
        result.clear();
        current.clear();
        sort(S.begin(), S.end());
        getSubsets(S, 0);
        return result;
    }

private:
    int n;
    vector<vector<int>> result;
    vector<int> current;

    void getSubsets(vector<int> &s, int k)
    {
        if (k == n)
        {
            result.push_back(current);
            return;
        }
        getSubsets(s, k + 1);
        current.push_back(s[k]);
        getSubsets(s, k + 1);
        current.pop_back();
    }
};

int main()
{
    return 0;
}