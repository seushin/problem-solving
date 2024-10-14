/*
* https://leetcode.com/problems//maximal-score-after-applying-k-operations
*/
#include <queue>
#include <vector>

class Solution
{
public:
	long long maxKelements(std::vector<int> &nums, int k)
	{
		std::priority_queue<int> pq(nums.begin(), nums.end());
		long long score = 0;

		for (int i = 0; i < k; i++)
		{
			score += op(pq);
		}
		return score;
	}

private:
	int op(std::priority_queue<int> &pq)
	{
		int value = pq.top();

		pq.pop();
		pq.push(next(value));
		return value;
	}

	int next(int n)
	{
		if (n % 3 == 0)
			return n / 3;
		else
			return n / 3 + 1;
	}
};
