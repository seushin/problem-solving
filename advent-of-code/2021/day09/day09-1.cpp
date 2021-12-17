#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

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

	ull res = 0;
	for (int y = 0; y < board.size(); ++y)
	{
		for (int x = 0; x < board[y].size(); ++x)
		{
			int num = board[y][x];

			if (y > 0 && board[y - 1][x] <= num)
				continue;
			if (y < board.size() - 1 && board[y + 1][x] <= num)
				continue;
			if (x > 0 && board[y][x - 1] <= num)
				continue;
			if (x < board[y].size() - 1 && board[y][x + 1] <= num)
				continue;
			res += num - '0' + 1;
		}
	}
	cout << endl << res << endl;
	return (0);
}
