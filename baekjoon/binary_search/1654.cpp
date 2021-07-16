#include <iostream>
using namespace std;

typedef unsigned long long ull;
#define MAXK 10001

int	K, N;
ull	a[MAXK];

int	get_n(ull length)
{
	int	res = 0;

	for (int i = 0; i < K; ++i)
	{
		res += a[i] / length;
	}
	return (res);
}

int	upper(ull first, ull last, int n)
{
	ull	mid;

	while (first <= last)
	{
		mid = first + (last - first) / 2;
		if (n <= get_n(mid))
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

	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> a[i];
	cout << upper(1, 2147483647, N);
	return (0);
}
