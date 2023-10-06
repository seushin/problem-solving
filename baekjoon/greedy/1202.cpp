/*
 * https://www.acmicpc.net/problem/1202
 * 보석 도둑
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

typedef unsigned long long ull;

ull solve(std::vector<std::pair<int, int> > &jewelries, std::multiset<int> &bags)
{
	ull sum = 0;

	std::sort(jewelries.begin(), jewelries.end(),
			  [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
				  return a.first == b.first ? a.second < b.second : a.first > b.first;
			  });

	for (auto jewelry : jewelries)
	{
		if (bags.empty())
			break;

		auto bag = bags.lower_bound(jewelry.second);
		if (bag != bags.end())
		{
			sum += jewelry.first;
			bags.erase(bag);
		}
	}

	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	std::vector<std::pair<int, int> > jewelries(N);
	std::multiset<int> bags;

	for (int i = 0; i < N; ++i)
		std::cin >> jewelries[i].second >> jewelries[i].first;

	int bag;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> bag;
		bags.insert(bag);
	}

	std::cout << solve(jewelries, bags) << std::endl;

	return 0;
}
