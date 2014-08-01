#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// This problem DOES NOT have an O(n) solution. It's a ``Keng'' actually.
// This solution with hash is O(n) at most situation, but O(n^2) worst.
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        vector<int> dedupNum;
        unordered_set<int> existingNum;
        for (int k : num)
        {
            if (existingNum.find(k) == existingNum.end())
            {
                dedupNum.push_back(k);
                existingNum.insert(k);
            }
        }

        unordered_map<int, int> mapSeqStartToEnd;
        unordered_map<int, int> mapSeqEndToStart;
        for (int k : dedupNum)
        {
            bool flag = false;
            if (mapSeqStartToEnd.find(k + 1) != mapSeqStartToEnd.end())
            {
                int val = mapSeqStartToEnd[k + 1];
                mapSeqStartToEnd.erase(mapSeqStartToEnd.find(k + 1));
                mapSeqStartToEnd[k] = val;
                mapSeqEndToStart[val] = k;
                flag = true;
            }
            if (mapSeqEndToStart.find(k) != mapSeqEndToStart.end())
            {
                if (flag)
                {
                    int val1 = mapSeqEndToStart[k];
                    int val2 = mapSeqStartToEnd[k];
                    mapSeqEndToStart.erase(mapSeqEndToStart.find(k));
                    mapSeqStartToEnd.erase(mapSeqStartToEnd.find(k));
                    mapSeqEndToStart[val2] = val1;
                    mapSeqStartToEnd[val1] = val2;
                }
                else
                {
                    int val = mapSeqEndToStart[k];
                    mapSeqEndToStart.erase(mapSeqEndToStart.find(k));
                    mapSeqEndToStart[k + 1] = val;
                    mapSeqStartToEnd[val] = k + 1;
                }
                flag = true;
            }
            if (!flag)
            {
                mapSeqStartToEnd[k] = k + 1;
                mapSeqEndToStart[k + 1] = k;
            }
        }

        int result = 0;
        for (auto p : mapSeqStartToEnd)
        {
            if (p.second - p.first > result)
            {
                result = p.second - p.first;
            }
        }

        return result;
    }
};