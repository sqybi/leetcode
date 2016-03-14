#include <climits>

class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		int sign = x >= 0 ? 1 : -1;
		x *= sign;
		while (x > 0) {
			res *= 10;
			res += x % 10;
			x /= 10;
		}
		// TODO: consider INT_MIN case
		if (res > INT_MAX) {
			return 0;
		}
		return sign * res;
	}
};

int main() {
	return 0;
}