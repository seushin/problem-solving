#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

vector<int> split(string str)
{
	vector<int> res;
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

ull getCost(vector<int> &crabs, int pos)
{
	ull res = 0;
	for (auto p : crabs)
		res += abs(pos - p);
	return (res);
}

ull solve(vector<int> &crabs, int left, int right)
{
	int mid = (left + right) / 2;

	if (left >= right)
		return (getCost(crabs, mid));
	ull leftFuel = solve(crabs, left, mid);
	ull rightFuel = solve(crabs, mid + 1, right);
	return (min(leftFuel, rightFuel));
}

int main()
{
	string input;
	getline(cin, input);

	vector<int> crabs = split(input);

	int left = *min_element(crabs.begin(), crabs.end());
	int right = *max_element(crabs.begin(), crabs.end());

	cout << solve(crabs, left, right) << endl;
	return (0);
}
