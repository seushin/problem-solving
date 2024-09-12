/*
 * https://leetcode.com/problems/count-the-number-of-consistent-strings
 */

#include <string>
#include <vector>

class Solution
{
public:
	int countConsistentStrings(std::string allowed, std::vector<std::string> &words)
	{
		int count = words.size();

		for (auto &word : words)
		{
			for (auto c : word)
			{
				if (allowed.find(c) == std::string::npos)
				{
					count--;
					break;
				}
			}
		}
		return count;
	}
};
