#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		map<int, int> sorted_nums;
		vector<int> result;
		
		for (int i = 0; i < n; i++)
		{
			sorted_nums.insert(make_pair(nums[i], i));
		}

		for (int i = 0; i < n; i++)
		{
			int m = target - nums[i];
			auto find_result = sorted_nums.find(m);
			if (find_result != sorted_nums.end() && find_result->second != i)
			{
				result.push_back(i + 1);
				//result.push_back((*find_result).second);
				result.push_back(find_result->second + 1);
				break;
			}
		}

		if (result[0] > result[1])
		{
			swap(result[0], result[1]);
		}

		return result;
	}
};

int main()
{
	return 0;
}