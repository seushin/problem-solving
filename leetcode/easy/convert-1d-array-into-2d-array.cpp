/*
 * https://leetcode.com/problems/convert-1d-array-into-2d-array
 */
#include <vector>

class Solution
{
public:
	std::vector<std::vector<int> > construct2DArray(std::vector<int> &original, int m, int n)
	{
		std::vector<std::vector<int> > res;

		if (original.size() != m * n)
			return res;
		for (auto pos = original.begin(); pos != original.end();)
		{
			res.push_back(std::vector<int>(pos, pos + n));
			pos += n;
		}
		return res;
	}
};
