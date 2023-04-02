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

	int A[N];
	for (int i = 0; i < N; ++i)
	{
		std::cin >> A[i];
	}

	/*
	 * 트리 M의 깊이 i에 해당하는 원소 중 가장 작은 원소의 인덱스를 저장.
	 * 다르게 말하면 트리 M의 평면도.
	 * 따라서 실제 LIS를 알기 위해선 반드시 parent를 저장해둬야 한다.
	 */
	std::vector<int> M;
	int parent[N];
	for (int i = 0; i < N; ++i)
	{
		/*
		 * A[i]를 트리 M의 깊이들에 해당하는 가장 작은 원소 중
		 * A[i]보다 작은 것들 중 가장 큰(lower_bound) 원소의 자식으로 삽입.
		 */
		int pos = std::lower_bound(M.begin(), M.end(), i,
								   [&A](auto a, auto b) -> bool { return A[a] < A[b]; }) -
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
