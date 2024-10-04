/*
 * https://leetcode.com/problems/make-sum-divisible-by-p
 */
#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	int minSubarray(std::vector<int> &nums, int p)
	{
		int remainder = 0;

		for (int num : nums)
		{
			remainder = (remainder + num) % p;
		}
		if (remainder == 0)
			return 0;

		int minLength = nums.size();
		int sum = 0;
		int rem = 0;
		std::unordered_map<int, int> m;

		m[0] = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			sum = (sum + nums[i]) % p;
			rem = (sum - remainder + p) % p;

			if (m.find(rem) != m.end())
				minLength = std::min(minLength, i - m[rem]);

			m[sum] = i;
		}
		return minLength == nums.size() ? -1 : minLength;
	}
};
