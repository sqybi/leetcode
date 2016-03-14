#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}

		int n = s.size();
		int m = 2 * numRows - 2;
		string res = "";
		for (int i = 0; i < n; i += m) {
			res += s[i];
		}
		for (int i = 1; i < numRows - 1; ++i) {
			for (int j = 0; ; ++j) {
				if (j * m - i > n - 1) {
					break;
				}
				if (j * m - i >= 0) {
					res += s[j * m - i];
				}

				if (j * m + i > n - 1) {
					break;
				}
				res += s[j * m + i];
			}
		}
		for (int i = numRows - 1; i < n; i += m) {
			res += s[i];
		}
		return res;
	}
};

int main() {
	return 0;
}