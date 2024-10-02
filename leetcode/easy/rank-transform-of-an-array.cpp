/*
 * https://leetcode.com/problems/rank-transform-of-an-array
 */
#include <set>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	std::vector<int> arrayRankTransform(std::vector<int> &arr)
	{
		std::unordered_map<int, int> rank;
		std::set<int> unique(arr.begin(), arr.end());
		std::vector<int> sorted(unique.begin(), unique.end());

		for (int i = 0; i < sorted.size(); ++i)
		{
			rank[sorted[i]] = i + 1;
		}

		std::vector<int> result(arr.size());

		for (int i = 0; i < arr.size(); ++i)
		{
			result[i] = rank[arr[i]];
		}
		return result;
	}
};
