/*
 * https://www.acmicpc.net/problem/1981
 * 배열에서 이동
 */

/*
 * 1안
 * - 실패
 * 단순하게 최소, 최대 값의 차이를 저장해서 길을 찾는 것은 의미가 없다.
 * ```
 * 3
 * 5   0 100
 * 10  5 0
 * 100 0 5
 * ```
 * 가 반례가 된다.
 * (0, 0)의 5에서 시작해 10으로 내려가는 것과
 * 옆의 0으로 가는 것은 차이값은 5로 같지만
 * 최소, 최대값이 다르기 때문에 같다고 할 수 없다.
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

#define MAXN 100

int	N;
int	board[MAXN][MAXN];
int	cache[MAXN][MAXN];

int	dy[4] = { 1, -1, 0, 0 };
int	dx[4] = { 0, 0, 1, -1 };

int	bfs()
{
	/* { { y, x }, { min, max } } */
	queue<pair<pii, pii> > q;
	int	smin = min(board[0][0], board[N - 1][N - 1]);
	int	smax = max(board[0][0], board[N - 1][N - 1]);

	memset(cache, -1, sizeof(cache));
	cache[0][0] = smax - smin;
	q.push({ {0, 0}, { smin, smax } });
	while (!q.empty())
	{
		int	y = q.front().first.first;
		int	x = q.front().first.second;
		int	mini = q.front().second.first;
		int	maxi = q.front().second.second;

		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int	ny = y + dy[i];
			int	nx = x + dx[i];

			if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1)
				continue;

			int	nmin = min(mini, board[ny][nx]);
			int	nmax = max(maxi, board[ny][nx]);

			if (cache[ny][nx] == -1 || nmax - nmin < cache[ny][nx])
			{
				cache[ny][nx] = nmax - nmin;
				q.push({ { ny, nx }, { nmin, nmax } });
			}
		}
	}
	return (cache[N - 1][N - 1]);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> board[y][x];
		}
	}
	int	min_diff = bfs();
	cout << min_diff;
	return (0);
}
