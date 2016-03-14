#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		string res;
		for (int i = 0; i < n; ++i) {
			// odd
			if (res.size() == 0) {
				res = s.substr(i, 1);
			}
			for (int j = 0; j < min(i, n - 1 - i); ++j) {
				if (s[i - j - 1] != s[i + j + 1]) {
					break;
				}
				if ((j + 1) * 2 + 1 > res.size()) {
					res = s.substr(i - j - 1, (j + 1) * 2 + 1);
				}
			}
			// even
			for (int j = 0; j < min(i + 1, n - 1 - i); ++j) {
				if (s[i - j] != s[i + j + 1]) {
					break;
				}
				if ((j + 1) * 2 > res.size()) {
					res = s.substr(i - j, (j + 1) * 2);
				}
			}
		}
		return res;
	}
};

int main() {
	return 0;
}