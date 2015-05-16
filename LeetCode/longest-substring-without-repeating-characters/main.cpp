#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> last_appear;
		int n = s.size();
		int* a = new int[n];
		int result = 0;
		auto t = n;
		for (int i = n - 1; i >= 0; i--)
		{
			if (last_appear.find(s[i]) == last_appear.end())
			{
				last_appear[s[i]] = n;
			}

			if (last_appear[s[i]] < t)
			{
				t = last_appear[s[i]];
			}
			last_appear[s[i]] = i;

			if (t - i > result)
			{
				result = t - i;
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}