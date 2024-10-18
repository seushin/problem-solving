/*
* https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets
*/
#include <vector>

class Solution
{
public:
	int countMaxOrSubsets(std::vector<int> &nums)
	{
		std::vector<int> subset;
		int maxOr = getMaxBitwiseOr(nums);

		return _countMaxOrSubsets(nums, subset, maxOr, 0);
	}

private:
	int _countMaxOrSubsets(const std::vector<int> &origin,
						   std::vector<int> &subset,
						   int target,
						   int nextIdx)
	{
		int count = 0;

		if (subset.size() && getMaxBitwiseOr(subset) == target)
			count++;
		for (int i = nextIdx; i < origin.size(); ++i)
		{
			subset.push_back(origin[i]);
			count += _countMaxOrSubsets(origin, subset, target, i + 1);
			subset.pop_back();
		}
		return count;
	}

	int getMaxBitwiseOr(const std::vector<int> &nums)
	{
		int maxOr = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			maxOr |= nums[i];
		}
		return maxOr;
	}
};
