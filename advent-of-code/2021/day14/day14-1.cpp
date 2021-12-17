#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

map<string, string> m;

string insertion(string &p)
{
	string res = p;

	for (int i = 0, pos = 1; i + 1 < p.size(); ++i, pos += 2)
	{
		res.insert(pos, m[p.substr(i, 2)]);
	}
	return (res);
}

int main()
{
	string polymer;
	string tmp;

	cin >> polymer;
	while (1)
	{
		string l, r;
		if (cin.eof())
			break;
		cin >> l >> tmp >> r;
		m[l] = r;
	}

	for (int it = 0; it < 10; ++it)
	{
		polymer = insertion(polymer);
		cout << polymer.size() << endl;
	}

	ull count[26] = { 0 };
	for (auto c : polymer)
	{
		count[c - 'A']++;
	}
	sort(count, count + 26);
	int i = 0;
	while (count[i] == 0)
		i++;
	cout << count[25] - count[i] << endl;

	return (0);
}
