#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		head = new DfaNode;
		BuildDfa(dict);
		result = "";
		CheckDfa(s, 0, head);
		return results.size() > 0;
	}

private:
	struct DfaNode
	{
		// next[0]: word end; next[i]: char ('a' + i - 1)
		DfaNode *next[27];
		DfaNode()
		{
			for (int i = 0; i < 27; i++)
			{
				next[i] = NULL;
			}
		}
	};

	DfaNode *head;
	string result;
	vector<string> results;

	void BuildDfa(unordered_set<string> &dict)
	{
		for (auto iterator = dict.begin(); iterator != dict.end(); iterator++)
		{
			int wordLength = iterator->length();
			auto word = *iterator;
			auto current = head;
			for (int i = 0; i < wordLength; i++)
			{
				int k = word[i] - 'a' + 1;
				if (current->next[k] == NULL)
				{
					current->next[k] = new DfaNode;
				}
				current = current->next[k];
			}
			if (current->next[0] == NULL)
			{
				current->next[0] = head;
			}
		}
	}

	void CheckDfa(string s, int pos, DfaNode *current)
	{
		if (pos == s.length())
		{
			if (current->next[0] == head)
			{
				results.push_back(result);
			}
			return;
		}
		int k = s[pos] - 'a' + 1;
		if (current->next[k] != NULL)
		{
			auto temp = result;
			result += s[pos];
			CheckDfa(s, pos + 1, current->next[k]);
			result = temp;
		}
		if (current->next[0] != NULL)
		{
			auto temp = result;
			result += " ";
			CheckDfa(s, pos, current->next[0]);
			result = temp;
		}
	}
};

int main()
{
	Solution solution;
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("aa");
	dict.insert("aaa");
	dict.insert("aaaa");
	dict.insert("aaaaa");
	dict.insert("aaaaaa");
	dict.insert("aaaaaaa");
	dict.insert("aaaaaaaa");
	dict.insert("aaaaaaaaa");
	dict.insert("aaaaaaaaaa");

	/*auto result = solution.wordBreak(s, dict);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}*/

	cout << (int)solution.wordBreak(s, dict);

	getchar();

	return 0;
}