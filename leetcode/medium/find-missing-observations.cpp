/*
 * https://leetcode.com/problems/find-missing-observations
 */
#include <numeric>
#include <vector>

class Solution
{
public:
	std::vector<int> missingRolls(std::vector<int> &rolls, int mean, int n)
	{
		int x = mean * (rolls.size() + n) - std::accumulate(rolls.begin(), rolls.end(), 0);

		if (x < n || x > n * 6)
			return std::vector<int>();

		std::vector<int> res(n, x / n);
		int rest = x % n;

		for (int i = 0; i < rest; i++)
			res[i]++;
		return res;
	}
};
