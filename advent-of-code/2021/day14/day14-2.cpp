#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

string start;
map<string, ull> cnt;
map<string, char> m;

void initCnt()
{
for (int i = 0; i + 1 < start.size(); ++i)
{
	string key = start.substr(i, 2);
	cnt[key]++;
}
}

bool compare(pair<char, ull> lhs, pair<char, ull> rhs)
{
return (lhs.second < rhs.second);
}

ull countAlpha()
{
map<char, ull> alpha;

for (auto p : cnt)
{
	alpha[p.first[0] - 'A'] += p.second;
}
alpha[start[start.size() - 1] - 'A']++;

pair<char, ull> maxp = *max_element(alpha.begin(), alpha.end(), compare);
pair<char, ull> minp = *min_element(alpha.begin(), alpha.end(), compare);

cout << "max : (" << (char)('A' + maxp.first) << ")" << maxp.second << endl;
cout << "min : (" << (char)('A' + minp.first) << ")" << minp.second << endl;

return (maxp.second - minp.second);
}

int main()
{
string tmp;

cin >> start;
while (1)
{
	string l, r;
	if (cin.eof())
		break;
	cin >> l >> tmp >> r;
	m[l] = r[0];
}
initCnt();

for (int it = 0; it < 40; ++it)
{
	map<string, ull> tmp;

	for (auto p : cnt)
	{
		string origin = p.first;
		string n1 = {origin[0], m[origin]};
		string n2 = {m[origin], origin[1]};

		tmp[n1] += p.second;
		tmp[n2] += p.second;
	}
	cnt = tmp;
}

cout << countAlpha() << endl;

return (0);
}
