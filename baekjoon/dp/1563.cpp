/*
 * https://www.acmicpc.net/problem/1563
 * 개근상
 */

#include <cstring>
#include <iostream>

#define MOD 1000000

#define MAX_N 1001
#define MAX_LATE 2
#define MAX_ABSENT 3

int N;
int cache[MAX_N][MAX_LATE][MAX_ABSENT];

int solve(int day, int late, int absent)
{
	if (late >= MAX_LATE || absent >= MAX_ABSENT)
		return 0;
	if (day == N)
		return 1;

	int &result = cache[day][late][absent];
	if (result != -1)
		return result;

	result = solve(day + 1, late, 0) % MOD;
	result += solve(day + 1, late + 1, 0) % MOD;
	result += solve(day + 1, late, absent + 1) % MOD;
	result %= MOD;

	return result;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::memset(cache, -1, sizeof(cache));

	std::cin >> N;
	std::cout << solve(0, 0, 0) << std::endl;

	return 0;
}
