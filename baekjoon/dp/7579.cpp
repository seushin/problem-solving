/*
 * https://www.acmicpc.net/problem/7579
 * 앱
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100
#define MAXM 1e7
#define MAXC 100
/*
 * also 1 <= m_i <= 1e7
 * 0 <= c_i <= 100
 * M <= m_1 + m_2 + ... + m_N
 *
 * M의 값이 캐싱하기엔 너무 크다
 * 따라서 비용 c를 이용해야한다
 * 문제를 바꾸면, 비용을 기준으로 최대 메모리의 합을 구한 뒤
 * 확보해야 하는 메모리 M이 넘는 최소 비용을 탐색한다
 */

int N, M;
int m[MAXN], c[MAXN];
int res[MAXN * MAXC + 1];

void solve(int costSum)
{
	for (int i = 0; i < N; ++i)
	{
		for (int cost = costSum; cost >= c[i]; --cost)
		{
			res[cost] = max(res[cost], res[cost - c[i]] + m[i]);
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> m[i];
	}

	int costSum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> c[i];
		costSum += c[i];
	}

	solve(costSum);
	for (int i = 0; i <= costSum; ++i)
	{
		if (res[i] >= M)
		{
			cout << i;
			break;
		}
	}

	return (0);
}
