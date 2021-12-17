#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

ull getBasinSize(vector<string> &board, int y, int x)
{
	if (y < 0 || y > board.size() - 1
			|| x < 0 || x > board[y].size() - 1)
		return (0);
	if (board[y][x] == '9')
		return (0);

	ull size = 1;
	board[y][x] = '9';

	const int dy[] = { 1, -1, 0, 0 };
	const int dx[] = { 0, 0, 1, -1 };
	for (int i = 0; i < 4; ++i)
		size += getBasinSize(board, y + dy[i], x + dx[i]);
	return (size);
}

int main()
{
	vector<string> board;
	string input;
	while (1)
	{
		getline(cin, input);
		if (cin.eof())
			break;
		board.push_back(input);
	}

	ull top[4] = { 0 };
	for (int y = 0; y < board.size(); ++y)
	{
		for (int x = 0; x < board[y].size(); ++x)
		{
			ull size = getBasinSize(board, y, x);
			if (size > top[1])
			{
				top[0] = size;
				sort(top, top + 4);
				top[0] = 0;
			}
		}
	}
	cout << endl << top[1] * top[2] * top[3] << endl;
	return (0);
}
