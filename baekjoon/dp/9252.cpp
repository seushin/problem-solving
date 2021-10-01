/*
 * https://www.acmicpc.net/problem/9252
 * LCS 2
 */
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXLEN 1000

int cache[MAXLEN + 1][MAXLEN + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= a.length(); ++i)
	{
		for (int j = 1; j <= b.length(); ++j)
		{
			if (a[i - 1] == b[j - 1])
				cache[i][j] = cache[i - 1][j - 1] + 1;
			else
				cache[i][j] = max(cache[i][j - 1], cache[i - 1][j]);
		}
	}
	int len = cache[a.length()][b.length()];
	cout << len << '\n';
	if (0 < len)
	{
		string res;
		int i = a.length(), j = b.length();
		while (res.length() < len)
		{
			if (a[i - 1] == b[j - 1])
			{
				res.insert(res.begin(), a[i - 1]);
				i--, j--;
			}
			else if (cache[i][j - 1] < cache[i - 1][j])
				i--;
			else
				j--;
		}
		cout << res;
	}
	return (0);
}
