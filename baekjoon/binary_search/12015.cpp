// https://www.acmicpc.net/problem/12015
#include <iostream>
using namespace std;

int	a[1000001];
int	cache[1000002];

int	lower_bnd(int first, int last, int value)
{
	while (first < last)
	{
		int	mid = first + (last - first) / 2;

		if (value <= cache[mid])
			last = mid;
		else
			first = mid + 1;
	}
	return (first);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cache[0] = a[0];
	int target, l = 0;
	for (int i = 1; i < n; ++i)
	{
		if (cache[l] < a[i])
		{
			l++;
			cache[l] = a[i];
		}
		else
		{
			target = lower_bnd(0, l, a[i]);
			cache[target] = a[i];
		}
	}
	cout << l + 1;
}
