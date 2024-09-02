/*
 * https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk
 */
#include <numeric>
#include <vector>

class Solution
{
public:
	int chalkReplacer(std::vector<int> &chalk, int k)
	{
		long long sum = 0;

		sum = std::accumulate(chalk.begin(), chalk.end(), sum);
		k %= sum;

		for (int i = 0; i < chalk.size(); ++i)
		{
			if (k < chalk[i])
				return i;
			k -= chalk[i];
		}
		return 0;
	}
};
