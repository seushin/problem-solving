#include <iostream>
using namespace std;

#define MAXN 1000001
typedef unsigned long long ull;

int	N, M;
ull	a[MAXN];

ull	get_m(ull length)
{
	ull	res = 0;

	for (int i = 0; i < N; ++i)
	{
		if (length < a[i])
			res += a[i] - length;
	}
	return (res);
}

ull	upper(ull first, ull last, ull m)
{
	while (first <= last)
	{
		ull	mid = first + (last - first) / 2;

		if (m <= get_m(mid))
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

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	cout << upper(0, 1e9, M);
	return (0);
}
