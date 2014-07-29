#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <limits>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int size = points.size();
		int maxCount = 0;
		if (size == 0)
		{
			return maxCount;
		}
		for (int i = 0; i < size - 1; i++)
		{
			vector<double> slopes;
			int base = 0;
			for (int j = i + 1; j < size; j++)
			{
				double slope = ((double)(points[i].x - points[j].x)) / (points[i].y - points[j].y);
				if (points[i].x == points[j].x && points[i].y == points[j].y)
				{
					base++;
				}
				else
				{
					if (points[i].y == points[j].y)
					{
						slope = numeric_limits<double>::max();
					}
					slopes.push_back(slope);
				}
			}
			sort(slopes.begin(), slopes.end());
			int slopesSize = slopes.size();
			if (slopesSize == 0)
			{
				if (base > maxCount)
				{
					maxCount = base;
				}
				continue;
			}
			int count = 1;
			for (int j = 1; j < slopesSize; j++)
			{
				if (abs(slopes[j] - slopes[j - 1]) < eps)
				{
					count++;
				}
				else
				{
					if (count + base > maxCount)
					{
						maxCount = count + base;
					}
					count = 1;
				}
			}
			if (count + base > maxCount)
			{
				maxCount = count + base;
			}
		}
		return maxCount + 1;
	}

private:
	const double eps = 1e-7;
};

void main()
{
	vector<Point> input;
	input.push_back(Point(2, 3));
	input.push_back(Point(3, 3));
	input.push_back(Point(-5, 3));
	Solution solution;
	cout << solution.maxPoints(input);
	getchar();
}