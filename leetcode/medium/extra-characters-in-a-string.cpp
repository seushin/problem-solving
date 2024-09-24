/*
 * https://leetcode.com/problems/extra-characters-in-a-string
 */
#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
public:
	int minExtraChar(std::string s, std::vector<std::string> &dictionary)
	{
		std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
		int n = s.size();
		std::vector<int> dp(n + 1);

		dp[0] = 0;
		for (int i = 1; i < n + 1; ++i)
		{
			dp[i] = dp[i - 1] + 1;
			for (int j = 0; j < i; ++j)
			{
				if (dict.find(s.substr(j, i - j)) != dict.end())
					dp[i] = std::min(dp[i], dp[j]);
			}
		}
		return dp[n];
	}
};
