#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (y == x
					|| (y == N - 1 - x)
					|| (y == 0 || y == N - 1) || (x == 0 || x == N - 1))
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
	return (0);
}
