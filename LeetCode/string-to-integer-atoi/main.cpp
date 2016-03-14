#include <string>
#include <climits>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int n = str.size();
		int i = 0;
		while (i < n && str[i] == ' ') {
			++i;
		}
		int sign = 1;
		long long res = 0;
		if (str[i] == '+') {
			++i;
		}
		else if (str[i] == '-') {
			sign = -1;
			++i;
		}
		while (i < n) {
			if (str[i] < '0' || str[i] > '9') {
				break;
			}
			res *= 10;
			res += str[i] - '0';
			if (sign == 1 && res > INT_MAX) {
				return INT_MAX;
			}
			else if (sign == -1 && -res < INT_MIN) {
				return INT_MIN;
			}
			++i;
		}
		return res * sign;
	}
};

int main() {
	return 0;
}