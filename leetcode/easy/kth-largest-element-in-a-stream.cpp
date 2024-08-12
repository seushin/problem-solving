/*
 * https://leetcode.com/problems/kth-largest-element-in-a-stream
 */
#include <queue>
#include <vector>
#include <iostream>

class KthLargest
{
private:
	int _k;
	std::priority_queue<int, std::vector<int>, std::greater<int>> _nums;

public:
	KthLargest(int k, std::vector<int> &nums) : _k(k), _nums(nums.begin(), nums.end())
	{
		while (_nums.size() > _k)
		{
			_nums.pop();
		}
	}

	int add(int val)
	{
		_nums.push(val);
		if (_nums.size() > _k)
			_nums.pop();
		return _nums.top();
	}
};
