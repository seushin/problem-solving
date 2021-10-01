/*
 * https://www.acmicpc.net/problem/1981
 * 배열에서 이동
 */
#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <queue>
using namespace std;

#define MAXN 100

int	dy[4] = { 1, -1, 0, 0 };
int	dx[4] = { 0, 0, 1, -1 };

int	N, MIN, MAX;
int	board[MAXN][MAXN];
int	visited[MAXN][MAXN];

bool	bfs(int min_value, int max_value)
{
	queue<pair<int, int> > q;

	if (board[0][0] < min_value || board[0][0] > max_value)
		return (false);
	memset(visited, 0, sizeof(visited));
	q.push({ 0, 0 });
	while (!q.empty())
	{
		int	y = q.front().first;
		int x = q.front().second;

		q.pop();
		if (y == N - 1 && x == N - 1)
			return (true);
		for (int i = 0; i < 4; ++i)
		{
			int	ny = y + dy[i];
			int	nx = x + dx[i];

			if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1)
				continue;
			if (!visited[ny][nx] &&
					min_value <= board[ny][nx] && board[ny][nx] <= max_value)
			{
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
	return (false);
}

bool	is_possible(int diff)
{
	for (int i = MIN; i <= MAX; ++i)
	{
		if (bfs(i, i + diff))
			return (true);
	}
	return (false);
}

int	solve()
{
	int	left = 0;
	int	right = MAX - MIN;

	while (left <= right)
	{
		int	mid = (left + right) / 2;
		if (is_possible(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (right + 1);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	MIN = 201;
	MAX = -1;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0;  x < N; ++x)
		{
			cin >> board[y][x];
			MIN = min(MIN, board[y][x]);
			MAX = max(MAX, board[y][x]);
		}
	}
	cout << solve();

	return (0);
}
