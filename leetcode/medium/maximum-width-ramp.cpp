/*
 * https://leetcode.com/problems/maximum-width-ramp
 */
#include <stack>
#include <vector>

class Solution
{
public:
	int maxWidthRamp(std::vector<int> &nums)
	{
		int width = 0;
		std::stack<int> s;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (s.empty() || nums[s.top()] > nums[i])
				s.push(i);
		}

		for (int i = nums.size() - 1; i >= 0 && !s.empty(); --i)
		{
			while (!s.empty() && nums[s.top()] <= nums[i])
			{
				width = std::max(width, i - s.top());
				s.pop();
			}
		}
		return width;
	}
};
