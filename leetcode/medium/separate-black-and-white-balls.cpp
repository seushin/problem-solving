/*
* https://leetcode.com/problems/separate-black-and-white-balls
*/
#include <string>

class Solution
{
public:
	// '0' is white, '1' is black
	// white | black
	long long minimumSteps(std::string s)
	{
		long long steps = 0;

		for (int left = 0, right = s.size() - 1; left < right; ++left, --right)
		{
			while (left < s.size() - 1 && s[left] == '0')
				left++;
			while (right > 0 && s[right] == '1')
				right--;
			if (left < right)
				steps += right - left;
		}
		return steps;
	}
};
