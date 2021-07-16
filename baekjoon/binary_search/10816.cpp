#include <algorithm>
#include <iostream>
using namespace std;

int	N, M;
int	a[500001];

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int	n;
		cin >> n;

		int	*low = lower_bound(a, a + N, n);
		int	*up = upper_bound(a, a + N, n);
		cout << up - low << " ";
	}
	return (0);
}
