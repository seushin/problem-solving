#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

vector<char> split(string str)
{
	vector<char> res;
	string::size_type pos = 0;

	for (auto &c : str)
		if (c == ',')
			c = ' ';
	while (!str.empty())
	{
		res.push_back(stol(str, &pos));
		str = str.substr(pos);
	}
	return (res);
}

void printResult(vector<ull> &days)
{
	ull res = 0;
	for (auto n : days)
		res += n;
	cout << res << endl;
}

int main()
{
	string input;

	getline(cin, input);

	vector<char> fish = split(input);
	vector<ull> days(9, 0);
	for (auto d : fish)
		days[d]++;
	for (int i = 0; i < 256; ++i)
	{
		ull zero = days[0];
		for (int i = 0; i < 8; ++i)
		{
			days[i] = days[i + 1];
		}
		days[6] += zero;
		days[8] = zero;
	}
	printResult(days);

	return (0);
}
