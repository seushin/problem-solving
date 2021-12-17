#include <iostream>
#include <string>
using namespace std;

#define MAXN 10

int flashCount = 0;
int board[MAXN][MAXN];
const int dy[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dx[] = { -1, 0, 1, 1, -1, 1, 0, -1 };

void getBoard()
{
	string input;
	for (int y = 0; y < MAXN; ++y)
	{
		cin >> input;
		for (int x = 0; x < MAXN; ++x)
		{
			board[y][x] = input[x] - '0';
		}
	}
}

void increase()
{
	for (int y = 0; y < MAXN; ++y)
		for (int x = 0; x < MAXN; ++x)
			board[y][x]++;
}

void findFlashed(int y, int x)
{
	if (board[y][x] < 10)
		return;
	board[y][x] = 0;
	flashCount++;
	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= MAXN || nx < 0 || nx >= MAXN)
			continue;

		int &target = board[ny][nx];
		if (target != 0)
		{
			target++;
			findFlashed(ny, nx);
		}
	}
}

void printBoard()
{
	for (int y = 0; y < MAXN; ++y)
	{
		for (int x = 0; x < MAXN; ++x)
		{
			int n = board[y][x];
			if (n == 0)
				cout << "\033[32m" << n << "\033[0m";
			else
				cout << n;
		}
		cout << endl;
	}
}

int main()
{
	getBoard();
	for (int step = 0; step < 100; ++step)
	{
		increase();
		for (int y = 0; y < MAXN; ++y)
			for (int x = 0; x < MAXN; ++x)
				findFlashed(y, x);
	}
	cout << endl;
	printBoard();
	cout << flashCount << endl;
	return (0);
}
