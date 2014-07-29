#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		int p = tokens.size();
		return eval(tokens, p);
	}

private:
	int eval(vector<string> &tokens, int &p)
	{
		p--;
		string token = tokens[p];
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			int right = eval(tokens, p);
			int left = eval(tokens, p);
			int result;
			if (token == "+")
			{
				result = left + right;
			}
			else if (token == "-")
			{
				result = left - right;
			}
			else if (token == "*")
			{
				result = left * right;
			}
			else if (token == "/")
			{
				result = left / right;
			}
			return result;
		}
		else
		{
			istringstream ss(token);
			int num;
			ss >> num;
			return num;
		}
	}
};

void main()
{
	vector<string> input;
	input.push_back("2");
	input.push_back("1");
	input.push_back("+");
	input.push_back("3");
	input.push_back("*");
	Solution solution;
	cout << solution.evalRPN(input);
	getchar();
}