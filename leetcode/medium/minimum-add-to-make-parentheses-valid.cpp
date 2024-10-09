/*
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
 */
#include <string>

class Solution
{
public:
	int minAddToMakeValid(std::string s)
	{
		int opening = 0;
		int closing = 0;

		for (char c : s)
		{
			if (c == '(')
				opening++;
			else
			{
				if (opening == 0)
					closing++;
				else
					opening--;
			}
		}
		return opening + closing;
	}
};
