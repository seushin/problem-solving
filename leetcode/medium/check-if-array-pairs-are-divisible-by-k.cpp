/*
 * https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k
 */
#include <map>
#include <vector>

class Solution
{
public:
	bool canArrange(std::vector<int> &arr, int k)
	{
		std::map<int, int> freq;

		for (int i = 0; i < arr.size(); i++)
		{
			arr[i] = ((arr[i] % k) + k) % k;
			freq[arr[i]]++;
		}

		for (const auto &f : freq)
		{
			int n = f.first;
			int count = f.second;
			int pair = k - n;

			if (n == 0 || n == pair)
			{
				if (count % 2 != 0)
					return false;
			}
			else
			{
				if (freq[pair] != count)
					return false;
			}
		}
		return true;
	}
};
