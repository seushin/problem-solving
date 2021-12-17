#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define MAXN 1500

bool board[MAXN][MAXN];

pair<int, int> parse(string input)
{
	pair<int, int> res;

	string::size_type pos = input.find(',');
	res.first = stol(input, &pos);
	res.second = stol(input.substr(pos + 1));
	return (res);
}

pair<int, int> parseFold(string input)
{
	pair<int, int> res;
	string label = "fold along ";
	int val;

	input = input.substr(label.size());
	val = stol(input.substr(2));
	if (input[0] == 'x')
		res.first = val;
	else
		res.second = val;
	return (res);
}

void foldBoard(pair<int, int> fold)
{
	if (fold.second == 0)
	{
		for (int y = 0; y < MAXN; ++y)
		{
			int dist = fold.first * 2;
			for (int x = 0; x < fold.first; ++x)
			{
				bool &target = board[y][x + dist];
				board[y][x] |= target;
				target = false;
				dist -= 2;
			}
		}
	}
	else
	{
		int dist = fold.second * 2;
		for (int y = 0; y < fold.second; ++y)
		{
			for (int x = 0; x < MAXN; ++x)
			{
				bool &target = board[y + dist][x];
				board[y][x] |= target;
				target = false;
			}
			dist -= 2;
		}
	}
}

void printBoard(int size)
{
	int count = 0;
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			if (board[y][x])
			{
				cout << "#";
				count++;
			}
			else
				cout << ".";
		}
		cout << endl;
	}
	cout << endl << count << endl;
}

int main()
{
	string input;
	while (1)
	{
		getline(cin, input);
		if (cin.eof())
			break;
		if (input.size() == 0)
			break;

		pair<int, int> pos = parse(input);

		board[pos.second][pos.first] = true;

		// cout << pos.first << " " << pos.second << endl;
	}
	while (1)
	{
		getline(cin, input);
		if (cin.eof())
			break;
		pair<int, int> fold = parseFold(input);
		foldBoard(fold);

		// cout << fold.first << " " << fold.second << endl;
	}

	printBoard(MAXN);

	return (0);
}
