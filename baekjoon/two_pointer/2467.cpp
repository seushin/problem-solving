/*
 * https://www.acmicpc.net/problem/2467
 * 용액 - gold5
 */
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100000

int N;
int sorted_list[MAXN];
int res[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> sorted_list[i];
	}
	res[0] = sorted_list[0];
	res[1] = sorted_list[N - 1];
	int left = 0, right = N - 1;
	int min_diff = 2e9;
	while (left < right)
	{
		if (abs(sorted_list[left] + sorted_list[right]) < abs(min_diff))
		{
			min_diff = sorted_list[left] + sorted_list[right];
			res[0] = sorted_list[left];
			res[1] = sorted_list[right];
		}
		if (min_diff == 0)
			break ;
		if (abs(sorted_list[left]) < abs(sorted_list[right]))
			right--;
		else
			left++;
	}
	cout << res[0] << " " << res[1];
	return (0);
}
