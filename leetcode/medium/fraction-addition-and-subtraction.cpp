/*
 * https://leetcode.com/problems/fraction-addition-and-subtraction
 */
#include <string>

class Solution
{
public:
	std::string fractionAddition(std::string expression)
	{
		int num = 0, den = 1;
		int i = 0;

		while (i < expression.size())
		{
			int n = 0, d = 0, sign = 1, g = 1;

			if (expression[i] == '-')
			{
				sign = -1;
				++i;
			}
			else if (expression[i] == '+')
			{
				sign = 1;
				++i;
			}
			while (expression[i] != '/')
				n = n * 10 + expression[i++] - '0';
			++i;
			while (i < expression.size() && expression[i] >= '0' && expression[i] <= '9')
				d = d * 10 + expression[i++] - '0';
			num = num * d + sign * den * n;
			den *= d;

			g = gcd(std::abs(num), den);
			num /= g;
			den /= g;
		}
		return std::to_string(num) + "/" + std::to_string(den);
	}

private:
	int gcd(int a, int b)
	{
		return (b == 0 ? a : gcd(b, a % b));
	}
};
