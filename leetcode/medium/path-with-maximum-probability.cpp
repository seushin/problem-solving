/*
 * https://leetcode.com/problems/path-with-maximum-probability
*/
#include <queue>
#include <vector>

class Solution
{
public:
	double maxProbability(int n,
						  std::vector<std::vector<int> > &edges,
						  std::vector<double> &succProb,
						  int startNode,
						  int endNode)
	{
		std::vector<std::vector<std::pair<int, double> > > adj(n);

		for (int i = 0; i < edges.size(); ++i)
		{
			auto &e = edges[i];

			adj[e[0]].push_back({e[1], succProb[i]});
			adj[e[1]].push_back({e[0], succProb[i]});
		}

		std::vector<double> res;
		std::queue<std::pair<int, double> > q;
		std::vector<double> visited(n, -1.0);

		q.push({startNode, 1.0});
		visited[startNode] = 1.0;
		while (!q.empty())
		{
			int node = q.front().first;
			double prob = q.front().second;

			q.pop();
			if (node == endNode)
			{
				res.push_back(prob);
				continue;
			}

			for (auto a : adj[node])
			{
				int nextNode = a.first;
				double nextProb = a.second * prob;

				if (visited[nextNode] < nextProb)
				{
					q.push({nextNode, nextProb});
					visited[nextNode] = nextProb;
				}
			}
		}

		return res.size() ? *std::max_element(res.begin(), res.end()) : 0.0;
	}
};
