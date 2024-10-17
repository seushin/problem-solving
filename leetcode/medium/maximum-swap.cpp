/*
* https://leetcode.com/problems/maximum-swap
*/
#include <string>
#include <vector>

class Solution
{
public:
	int maximumSwap(int num)
	{
		std::string numstr = std::to_string(num);
		std::vector<int> mstack;

		for (int i = 0; i < numstr.size(); ++i)
		{
			while (!mstack.empty() && numstr[mstack.back()] < numstr[i])
			{
				mstack.pop_back();
			}
			mstack.push_back(i);
		}

		if (mstack.size() == numstr.size())
			return num;
		for (int i = 0; i < mstack.size(); ++i)
		{
			if (i == mstack[i])
				continue;

			int j = i;

			while (j + 1 < mstack.size() && numstr[mstack[j]] == numstr[mstack[j + 1]])
				++j;
			numstr = swapChar(numstr, i, mstack[j]);
			break;
		}
		return std::stoi(numstr);
	}

private:
	std::string swapChar(std::string s, int i, int j)
	{
		int tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		return s;
	}
};
