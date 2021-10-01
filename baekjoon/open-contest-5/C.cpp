#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

#define MAXN 20

int N;
int arr[MAXN];
set<ll> sum;

void cal_sum(int start, ll total)
{
	if (start >= N)
		return ;
	for (int i = start; i < N; ++i)
	{
		total += arr[i];
		sum.insert(total);
		cal_sum(i + 1, total);
		total -= arr[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	ll M = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		M += arr[i];
	}
	cal_sum(0, 0);
	cout << M - sum.size();

	// cout << "sum\n";
	// for (auto it : sum)
	// 	cout << it << '\n';
	return (0);
}
