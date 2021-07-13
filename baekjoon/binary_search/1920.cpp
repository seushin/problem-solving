// https://www.acmicpc.net/problem/1920
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 100001

int N, M;
int a[MAXN];

int solve(int m)
{
	int start = 0;
	int end = N - 1;

	while (0 <= end - start)
	{
		int mid = (start + end) / 2;

		if (a[mid] == m)
			return (1);
		else if (a[mid] < m)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}

int main()
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
		int m; cin >> m;
		cout << solve(m) << '\n';
	}
	return (0);
}
