/*
 * https://www.acmicpc.net/problem/14002
 * https://www.acmicpc.net/problem/14003
 * 가장 긴 증가하는 부분 수열 4, 5
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int A[N], parent[N];
	for (int i = 0; i < N; ++i)
	{
		std::cin >> A[i];
	}

	std::vector<int> M;
	for (int i = 0; i < N; ++i)
	{
		int pos = std::lower_bound(M.begin(), M.end(), A[i],
								   [&A](auto i, auto b) -> bool { return A[i] < b; }) -
				  M.begin();

		if (pos == M.size())
		{
			M.push_back(i);
		}
		else
		{
			M[pos] = i;
		}
		parent[i] = pos == 0 ? -1 : M[pos - 1];
	}

	std::vector<int> LIS;
	int last_index = M.back();
	while (last_index != -1)
	{
		LIS.push_back(A[last_index]);
		last_index = parent[last_index];
	}

	std::cout << LIS.size() << '\n';
	for (auto it = LIS.rbegin(), ite = LIS.rend(); it != ite; ++it)
	{
		std::cout << *it << ' ';
	}

	return (0);
}
