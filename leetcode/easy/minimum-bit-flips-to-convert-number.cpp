/*
 * https://leetcode.com/problems/minimum-bit-flips-to-convert-number
 */

class Solution
{
public:
	int minBitFlips(int start, int goal)
	{
		start ^= goal;
		return countBit(start);
	}

private:
	int countBit(int n)
	{
		int count = 0;

		while (n)
		{
			n &= n - 1;
			count++;
		}
		return count;
	}
};
