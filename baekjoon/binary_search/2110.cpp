// https://www.acmicpc.net/problem/2110
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 200001

int	N, C;
int	a[MAXN];

int	get_c(int dist)
{
	int	res = 1;
	int	prev = 0;

	for (int i = 1; i < N; ++i)
	{
		if (dist <= a[i] - a[prev])
		{
			res++;
			prev = i;
		}
	}
	return (res);
}

int	upper(int first, int last, int c)
{
	while (first <= last)
	{
		int	mid = first + (last - first) / 2;

		if (c <= get_c(mid))
			first = mid + 1;
		else
			last = mid - 1;
	}
	return (first - 1);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + N);
	cout << upper(0, 1e9, C);
	return (0);
}
