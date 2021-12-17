#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

bool isSubstr(string sig, string sub)
{
	for (int i = 0; i < sub.size(); ++i)
	{
		bool flag = false;
		for (auto c : sig)
		{
			if (c == sub[i])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			return (false);
	}
	return (true);
}

string findDigit(vector<string> &digit, int size, string substr)
{
	string res;

	for (int i = 0; i < digit.size(); ++i)
	{
		if (digit[i].size() == size && isSubstr(digit[i], substr))
		{
			res = digit[i];
			digit.erase(digit.begin() + i);
			break;
		}
	}
	return (res);
}

vector<string> getPattern(vector<string> digit)
{
	vector<string> pattern(10, "");

	// unique digit
	pattern[1] = findDigit(digit, 2, "");
	pattern[7] = findDigit(digit, 3, "");
	pattern[4] = findDigit(digit, 4, "");
	pattern[8] = findDigit(digit, 7, "");

	pattern[3] = findDigit(digit, 5, pattern[7]);
	pattern[9] = findDigit(digit, 6, pattern[4]);
	pattern[0] = findDigit(digit, 6, pattern[7]);
	pattern[6] = findDigit(digit, 6, "");
	if (isSubstr(pattern[6], digit[0]))
	{
		pattern[2] = digit[1];
		pattern[5] = digit[0];
	}
	else
	{
		pattern[2] = digit[0];
		pattern[5] = digit[1];
	}
	return (pattern);
}

bool isEqual(string lhs, string rhs)
{
	sort(lhs.begin(), lhs.end());
	sort(rhs.begin(), rhs.end());
	return (lhs == rhs);
}

int sigtoi(string digit, vector<string> &signal)
{
	for (int i = 0; i < 10; ++i)
	{
		if (isEqual(signal[i], digit))
			return (i);
	}
	cout << "err!" << endl;
	return (-1);
}

int getOutput(vector<string> &digit)
{
	vector<string> pattern = getPattern(vector<string>(digit.begin(), digit.begin() + 10));
	int res = 0;

	for (int i = 0; i < 4; ++i)
	{
		res *= 10;
		res += sigtoi(digit[i + 10], pattern);
	}
	return (res);
}

int main()
{
	string input;

	ull res = 0;
	while (1)
	{
		getline(cin, input);
		if (cin.eof())
			break;

		vector<string> digit(14, "");

		for (int i = 0; i < 14; ++i)
		{
			int len = input.find(' ');
			string tmp = input.substr(0, len);
			if (tmp == "|")
			{
				input = input.substr(len + 1);
				len = input.find(' ');
				tmp = input.substr(0, len);
			}
			digit[i] = tmp;
			input = input.substr(len + 1);
		}
		res += getOutput(digit);
	}
	cout << endl << res << endl;
	return (0);
}
