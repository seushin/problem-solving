/*
 * https://www.acmicpc.net/problem/1005
 * ACM Craft
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 1001

int T, N, K, W;
int D[MAXN], indegree[MAXN], res[MAXN];
vector<int> adj[MAXN];
queue<int> q;

void solve()
{
	while (!q.empty())
	{
		int v = q.front();

		q.pop();
		for (int i = 0; i < adj[v].size(); ++i)
		{
			int w = adj[v][i];

			res[w] = max(res[w], res[v] + D[w]);
			if (--indegree[w] == 0)
				q.push(w);
		}
	}
}

void input()
{
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> D[i];
	}
	for (int i = 0; i < K; ++i)
	{
		int v, w;
		cin >> v >> w;
		adj[v].push_back(w);
		indegree[w]++;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			res[i] = D[i];
		}
	}
	cin >> W;
}

void init()
{
	memset(indegree, 0, sizeof(indegree));
	memset(res, 0, sizeof(res));
	q = queue<int>();
	for (int i = 1; i <= N; ++i)
	{
		adj[i].clear();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		init();
		input();
		solve();
		cout << res[W] << '\n';
	}
	return (0);
}
