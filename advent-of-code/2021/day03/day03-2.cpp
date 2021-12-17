#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

bool getCommonBit(vector<string> &v, int idx, bool b)
{
	int countOneBit = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i][idx] == '1')
			countOneBit++;
	}
	bool commonBit = countOneBit > v.size() / 2;
	if (countOneBit * 2 == v.size())
		return (b);
	else if (b)
		return (commonBit);
	return (!commonBit);
}

string solve(vector<string> &v, int idx, bool b)
{
	if (v.size() == 1)
		return (v[0]);
	char commonBit = getCommonBit(v, idx, b) + '0';
	cout << "common bit " << commonBit << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		string &s = v[i];
		if (s[idx] != commonBit)
		{
			v.erase(v.begin() + i);
			i--;
		}
	}
	return (solve(v, idx + 1, b));
}

ull strToUll(string &s)
{
	ull res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res <<= 1;
		if (s[i] == '1')
			res += 1;
	}
	return (res);
}

int main()
{
	vector<string> v;
	string input;
	int bitsum[12] = { 0 };
	int size = 0;

	while (1)
	{
		cin >> input;
		if (cin.eof())
			break;
		v.push_back(input);
	}
	vector<string> tmp;
	tmp = v;
	string oxy = solve(tmp, 0, 1);
	tmp = v;
	string co2 = solve(tmp, 0, 0);

	cout << "oxy : " << oxy << endl;
	cout << "co2 : " << co2 << endl;
	cout << "oxy : " << strToUll(oxy) << endl;
	cout << "co2 : " << strToUll(co2) << endl;
	return (0);
}
