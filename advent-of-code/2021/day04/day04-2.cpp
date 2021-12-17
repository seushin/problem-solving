#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> split(string str)
{
	vector<int> res;
	string::size_type pos = 0;

	while (!str.empty())
	{
		res.push_back(stol(str, &pos));
		str = str.substr(pos);
	}
	return (res);
}

int hasBingo(vector<vector<vector<int>>> &boards)
{
	for (int i = 0; i < boards.size(); ++i)
	{
		for (int y = 0; y < boards[i].size(); ++y)
		{
			bool isBingo = true;
			for (int x = 0; x < boards[i][y].size(); ++x)
			{
				if (boards[i][y][x] != -1)
				{
					isBingo = false;
					break;
				}
			}
			if (isBingo)
				return (i);
		}
		for (int x = 0; x < boards[i][0].size(); ++x)
		{
			bool isBingo = true;
			for (int y = 0; y < boards[i].size(); ++y)
			{
				if (boards[i][y][x] != -1)
				{
					isBingo = false;
					break;
				}
			}
			if (isBingo)
				return (i);
		}
	}
	return (-1);
}

ll bingo(vector<vector<vector<int>>> &boards, vector<int> &random)
{
	for (auto num : random)
	{
		for (auto &board : boards)
		{
			for (auto &line : board)
			{
				for (int &n : line)
				{
					if (n == num)
					{
						n = -1;
					}
				}
			}
		}
		int i = -1;
		while (boards.size() > 1 && (i = hasBingo(boards)) != -1)
			boards.erase(boards.begin() + i);
		if (boards.size() == 1 && (i = hasBingo(boards) != -1))
		{
			ll sum = 0;
			for (auto line : boards[0])
			{
				for (auto n : line)
				{
					if (n != -1)
						sum += n;
				}
			}
			cout << "sum, num : " << sum << " " << num << endl;
			return (sum * num);
		}
	}
	return (0);
}

int main()
{
	string input;

	getline(cin, input);

	for (auto &c : input)
		if (c == ',')
			c = ' ';
	vector<int> randomNum = split(input);

	// empty line
	getline(cin, input);

	vector<vector<vector<int>>> boards;
	while (cin.good())
	{
		vector<vector<int>> board;

		while (cin.good())
		{
			getline(cin, input);
			if (input == "")
				break;
			board.push_back(split(input));
		}
		boards.push_back(board);
	}

	ll res = bingo(boards, randomNum);

	cout << "result : " << res << endl;

	return (0);
}
