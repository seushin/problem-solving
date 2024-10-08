/*
 https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
 */
#include <string>

class Solution
{
public:
	int minSwaps(std::string s)
	{
		int swapCount = 0;
		int openB = 0;
		int closeB = 0;

		for (int front = 0, back = s.size() - 1; front <= back;)
		{
			if (openB != -1)
			{
				if (s[front] == '[')
					openB++;
				else
					openB--;
				front++;
			}
			if (closeB != -1)
			{
				if (s[back] == ']')
					closeB++;
				else
					closeB--;
				back--;
			}
			if (openB == -1 && closeB == -1)
			{
				swapCount++;
				openB = closeB = 1;
			}
		}
		return swapCount;
	}
};
