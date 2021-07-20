// https://www.acmicpc.net/problem/10217
#include <cstring>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 101
#define MAXM 10001

typedef struct 
{
	int	v;
	int	c;
	int	d;
}	data_t;

int	N, M, K;
vector<data_t>	adj[MAXN];
int	cache[MAXN][MAXM];

void	init()
{
	// 벡터, 캐시 배열 초기화
	for (int i = 1; i <= N; ++i)
		adj[i].clear();
	memset(cache, -1, sizeof(cache));
}

int	solve(int start)
{
	priority_queue<pair<int, pair<int, int> > >	q;
	data_t	data;

	q.push(make_pair(0, make_pair(0, start)));
	while (!q.empty())
	{
		int	dist = -q.top().first;
		int	cost = q.top().second.first;
		int	u = q.top().second.second;

		q.pop();
		if (M < cost)
			continue;
		if (cache[u][cost] != -1 && cache[u][cost] < dist)
			continue;
		if (u == N)
			return (dist);
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int	v = adj[u][i].v;
			int	next_cost = cost + adj[u][i].c;
			int	next_dist = dist + adj[u][i].d;

			if (M < next_cost)
				continue;
			if (cache[v][next_cost] == -1 || next_dist < cache[v][next_cost])
			{
				cache[v][next_cost] = next_dist;
				q.push(make_pair(-next_dist, make_pair(next_cost, v)));
			}
		}
	}
	return (-1);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	T; cin >> T;
	while (T--)
	{
		init();

		cin >> N >> M >> K;
		for (int i = 0; i < K; ++i)
		{
			int	u;
			data_t	tmp;

			cin >> u >> tmp.v >> tmp.c >> tmp.d;
			adj[u].push_back(tmp);
		}
		int	res = solve(1);
		if (res == -1)
			cout << "Poor KCM\n";
		else
			cout << res << "\n";
	}
	return (0);
}
