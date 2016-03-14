#include <string>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int* a = new int[s.size()];
		for (int i = 0; i < s.size(); ++i) {
			a[i] = convert(s[i]);
		}
		int result = 0;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (a[i] < a[i + 1]) {
				result -= a[i];
			}
			else {
				result += a[i];
			}
		}
		result += a[s.size() - 1];
		return result;
	}

	int convert(char c) {
		switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			// Should never run this line
			return 0;
		}
	}
};

int main() {
	return 0;
}