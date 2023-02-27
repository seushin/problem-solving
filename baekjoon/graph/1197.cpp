/*
** https://www.acmicpc.net/problem/1197
** 최소 스패닝 트리
*/
#include <algorithm>
#include <iostream>
#include <vector>

struct DisjointSet
{
	std::vector<int> parent;

	DisjointSet(int n)
	{
		for (int i = 0; i <= n; i++)
			parent.push_back(i);
	}

	int find(int x)
	{
		if (x == parent[x])
			return x;
		return find(parent[x]);
	}

	void push(int x, int y)
	{
		x = find(x);
		y = find(y);
		parent[y] = x;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int V, E;
	std::vector<std::pair<int, std::pair<int, int> > > adj;

	std::cin >> V >> E;
	while (E--)
	{
		int A, B, C;
		std::cin >> A >> B >> C;
		adj.push_back({C, {A, B}});
	}
	std::sort(adj.begin(), adj.end());

	DisjointSet set(V);
	std::vector<int> res;
	for (auto it = adj.begin(); it != adj.end(); it++)
	{
		const int a = it->second.first;
		const int b = it->second.second;
		const int c = it->first;

		if (set.find(a) != set.find(b))
		{
			set.push(a, b);
			res.push_back(c);
		}
		if (res.size() == V)
			break;
	}

	int sum = 0;
	for (auto n : res)
		sum += n;
	std::cout << sum << std::endl;
}
