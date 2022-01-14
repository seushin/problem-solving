/*
 * https://www.acmicpc.net/problem/2667
 * 단지번호붙이기
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 25

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int N;
char board[MAXN][MAXN];

int dfs(int y, int x)
{
	if (board[y][x] == '0')
		return (0);
	int res = 1;

	board[y][x] = '0';
	for (int i = 0; i < 4; ++i)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1)
			continue;
		res += dfs(ny, nx);
	}
	return (res);
}

vector<int> solve()
{
	vector<int> counts;
	int count;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			if ((count = dfs(y, x)) != 0)
				counts.push_back(count);
	return (counts);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> board[y][x];

	vector<int> counts = solve();

	sort(counts.begin(), counts.end());
	cout << counts.size() << endl;
	for (auto c : counts)
		cout << c << endl;
	return (0);
}
