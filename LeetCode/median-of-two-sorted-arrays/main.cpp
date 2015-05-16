#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		if ((n1 + n2) % 2 == 1)
		{
			// find in nums1
			int l = 0;
			int r = n1;
			while (l < r)
			{
				int m = (l + r) / 2;
				int less1 = find_less_than_count(nums1[m], nums1);
				int greater1 = find_greater_than_count(nums1[m], nums1);
				int less2 = find_less_than_count(nums1[m], nums2);
				int greater2 = find_greater_than_count(nums1[m], nums2);
				auto less = less1 + less2;
				auto greater = greater1 + greater2;
				int same = n1 + n2 - less - greater;
				if (less <= greater && less + same > greater)
				{
					return nums1[m];
				}
				else if (less >= greater && less < greater + same)
				{
					return nums1[m];
				}
				else if (less < greater)
				{
					l = m + 1;
				}
				else
				{
					r = m;
				}
			}

			// find in nums2
			l = 0;
			r = n2;
			while (l < r)
			{
				int m = (l + r) / 2;
				int less1 = find_less_than_count(nums2[m], nums1);
				int greater1 = find_greater_than_count(nums2[m], nums1);
				int less2 = find_less_than_count(nums2[m], nums2);
				int greater2 = find_greater_than_count(nums2[m], nums2);
				auto less = less1 + less2;
				auto greater = greater1 + greater2;
				int same = n1 + n2 - less - greater;
				if (less <= greater && less + same > greater)
				{
					return nums2[m];
				}
				else if (less >= greater && less < greater + same)
				{
					return nums2[m];
				}
				else if (less < greater)
				{
					l = m + 1;
				}
				else
				{
					r = m;
				}
			}
		}
		else
		{
			// find in nums1
			int l = 0;
			int r = n1;
			while (l < r)
			{
				int m = (l + r) / 2;
				int less1 = find_less_than_count(nums1[m], nums1);
				int greater1 = find_greater_than_count(nums1[m], nums1);
				int less2 = find_less_than_count(nums1[m], nums2);
				int greater2 = find_greater_than_count(nums1[m], nums2);
				auto less = less1 + less2;
				auto greater = greater1 + greater2;
				int same = n1 + n2 - less - greater;
				if (less <= greater && less + same == greater)
				{
					if ((greater1 == 0 ? INT_MAX : nums1[n1 - greater1]) < (greater2 == 0 ? INT_MAX : nums2[n2 - greater2]))
					{
						return (nums1[m] + nums1[n1 - greater1]) / 2.0;
					}
					else
					{
						return (nums1[m] + nums2[n2 - greater2]) / 2.0;
					}
				}
				else if (less <= greater && less + same > greater)
				{
					return nums1[m];
				}
				else if (less >= greater && less == greater + same)
				{
					if ((less1 == 0 ? INT_MIN : nums1[less1 - 1]) < (less2 == 0 ? INT_MIN : nums2[less2 - 1]))
					{
						return (nums1[m] + nums2[less2 - 1]) / 2.0;
					}
					else
					{
						return (nums1[m] + nums1[less1 - 1]) / 2.0;
					}
				}
				else if (less >= greater && less < greater + same)
				{
					return nums1[m];
				}
				else if (less < greater)
				{
					l = m + 1;
				}
				else
				{
					r = m;
				}
			}

			// find in nums2
			l = 0;
			r = n2;
			while (l < r)
			{
				int m = (l + r) / 2;
				int less1 = find_less_than_count(nums2[m], nums1);
				int greater1 = find_greater_than_count(nums2[m], nums1);
				int less2 = find_less_than_count(nums2[m], nums2);
				int greater2 = find_greater_than_count(nums2[m], nums2);
				auto less = less1 + less2;
				auto greater = greater1 + greater2;
				int same = n1 + n2 - less - greater;
				if (less <= greater && less + same == greater)
				{
					if ((greater1 == 0 ? INT_MAX : nums1[n1 - greater1]) < (greater2 == 0 ? INT_MAX : nums2[n2 - greater2]))
					{
						return (nums2[m] + nums1[n1 - greater1]) / 2.0;
					}
					else
					{
						return (nums2[m] + nums2[n2 - greater2]) / 2.0;
					}
				}
				else if (less <= greater && less + same > greater)
				{
					return nums2[m];
				}
				else if (less >= greater && less == greater + same)
				{
					if ((less1 == 0 ? INT_MIN : nums1[less1 - 1]) < (less2 == 0 ? INT_MIN : nums2[less2 - 1]))
					{
						return (nums2[m] + nums2[less2 - 1]) / 2.0;
					}
					else
					{
						return (nums2[m] + nums1[less1 - 1]) / 2.0;
					}
				}
				else if (less >= greater && less < greater + same)
				{
					return nums2[m];
				}
				else if (less < greater)
				{
					l = m + 1;
				}
				else
				{
					r = m;
				}
			}
		}
	}

	int find_less_than_count(int k, vector<int> &num)
	{
		int n = num.size();

		int l = 0;
		int r = n;
		int result = -1;
		int m;
		while (l < r)
		{
			m = (l + r) / 2;
			if (num[m] >= k)
			{
				r = m;
			}
			else if (num[m] < k)
			{
				result = m;
				l = m + 1;
			}
		}

		return result + 1;
	}

	int find_greater_than_count(int k, vector<int> &num)
	{
		int n = num.size();

		int l = 0;
		int r = n;
		int result = n;
		int m;
		while (l < r)
		{
			m = (l + r) / 2;
			if (num[m] > k)
			{
				result = m;
				r = m;
			}
			else if (num[m] <= k)
			{
				l = m + 1;
			}
		}

		return n - result;
	}
};

int main()
{
	Solution solution;

	vector<int> a;
	vector<int> b;
	b.push_back(1);
	cout << solution.findMedianSortedArrays(a, b);

	getchar();

	return 0;
}
