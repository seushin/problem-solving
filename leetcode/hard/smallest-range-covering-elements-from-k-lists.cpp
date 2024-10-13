/*
* https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists
*/
#include <queue>
#include <vector>

class Solution
{
public:
	std::vector<int> smallestRange(std::vector<std::vector<int> > &nums)
	{
		typedef std::pair<int, std::pair<int, int> > Node;
		std::priority_queue<Node, std::vector<Node>, std::greater<Node> > pq;
		int maxValue = nums[0][0];

		for (int i = 0; i < nums.size(); ++i)
		{
			pq.push({nums[i][0], {i, 0}});
			maxValue = std::max(maxValue, nums[i][0]);
		}

		std::vector<int> res = {pq.top().first, maxValue};

		while (!pq.empty())
		{
			auto node = pq.top();
			int i = node.second.first;
			int j = node.second.second;

			pq.pop();
			if ((res[1] - res[0] > maxValue - nums[i][j]))
				res = {nums[i][j], maxValue};
			if (++j == nums[i].size())
				break;
			pq.push({nums[i][j], {i, j}});
			maxValue = std::max(maxValue, nums[i][j]);
		}
		return res;
	}
};
