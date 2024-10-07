/*
 * https://leetcode.com/problems/minimum-string-length-after-removing-substrings
 */
#include <string>

class Solution
{
public:
	int minLength(std::string s)
	{
		std::string sub1 = "AB";
		std::string sub2 = "CD";

		while (true)
		{
			auto pos1 = s.find(sub1);
			auto pos2 = s.find(sub2);

			if (pos1 != std::string::npos)
				s.erase(pos1, sub1.size());
			else if (pos2 != std::string::npos)
				s.erase(pos2, sub2.size());
			else
				break;
		}
		return s.size();
	}
};
