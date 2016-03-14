#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		ls = s.size();
		lp = p.size();

		int available_char_s = ls;
		for (char c : s) {
			if (c == '*') {
				available_char_s -= 2;
			}
		}
		int available_char_p = lp;
		for (char c : p) {
			if (c == '*') {
				available_char_p -= 2;
			}
		}

		if (available_char_p > available_char_s) {
			return false;
		}

		return match(s, p, 0, 0, available_char_s - available_char_p);
	}

	bool match(const string& s, const string& p, int ps, int pp, int k) {
		if (ps == ls && pp == lp) {
			return true;
		}
		if (ps >= ls) {
			return check(p, pp);
		}
		if (pp >= lp) {
			return false;
		}
		if (pp < lp - 1 && p[pp + 1] == '*') {
			if (p[pp] == '.') {
				for (int i = 0; i <= k; ++i) {
					if (match(s, p, ps + i, pp + 2, k - i)) {
						return true;
					}
				}
				return false;
			}
			else {
				if (s[ps] != p[pp]) {
					return match(s, p, ps, pp + 2, k);
				}
				char ch = s[ps];
				for (int i = 0; i <= k && (i == 0 || s[ps + i - 1] == ch); ++i) {
					if (match(s, p, ps + i, pp + 2, k - i)) {
						return true;
					}
				}
			}
		}
		else {
			if (p[pp] == '.') {
				return match(s, p, ps + 1, pp + 1, k);
			}
			else {
				if (s[ps] != p[pp]) {
					return false;
				}
				return match(s, p, ps + 1, pp + 1, k);
			}
		}
	}

	bool check(const string& p, int pp) {
		while (pp < lp) {
			if (p[pp + 1] != '*') return false;
			pp += 2;
		}
		return true;
	}

	int ls;
	int lp;
};

int main() {
	return 0;
}