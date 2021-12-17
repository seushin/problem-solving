#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

#define MAXN 1000
int board[MAXN][MAXN];

bool isDiagonal(pii lhs, pii rhs)
{
	int slope1 = abs(lhs.first - rhs.first);
	int slope2 = abs(lhs.second - rhs.second);

	return (slope1 == slope2);
}

pii &operator+=(pii &lhs, pii &rhs)
{
	if (isDiagonal(lhs, rhs))
	{
		if (lhs.second < rhs.second)
			lhs.second++;
		else if (lhs.second > rhs.second)
			lhs.second--;
	}
	if (lhs.first == rhs.first)
		lhs.second++;
	else
		lhs.first++;
	return (lhs);
}

void draw(pii p1, pii p2)
{
	while (p1 <= p2)
	{
		board[p1.second][p1.first]++;
		p1 += p2;
	}
}

int main()
{
	pii p1, p2;
	char tmp[5];

	while (scanf("%d,%d %s %d,%d",
				&p1.first, &p1.second, tmp, &p2.first, &p2.second) != -1)
	{
		if (p1 > p2)
			p1.swap(p2);
		if (p1.first == p2.first || p1.second == p2.second || isDiagonal(p1, p2))
			draw(p1, p2);
	}

	// draw board
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
			cout << board[y][x] << " ";
		cout << endl;
	}

	// result
	int count = 0;
	for (int y = 0; y < MAXN; ++y)
		for (int x = 0; x < MAXN; ++x)
			if (board[y][x] > 1)
				count++;
	printf("\n%d\n", count);
	return (0);
}
