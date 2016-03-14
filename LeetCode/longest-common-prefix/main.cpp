#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		}
		string common = strs[0];
		for (int i = 1; i < strs.size(); ++i) {
			common = getCommonPrefix(common, strs[i]);
		}
		return common;
	}

	string getCommonPrefix(string a, string b) {
		string result = "";
		for (int i = 0; i < a.size() && i < b.size() && a[i] == b[i]; ++i) {
			result += a[i];
		}
		return result;
	}
};

int main() {
	return 0;
}