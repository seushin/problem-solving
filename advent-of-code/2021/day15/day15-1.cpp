#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

vector<vector<int>> board;

int bfs()
{
	queue<pair<int, int>> q;
	vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), -1));

	visited[0][0] = 0;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[ny].size())
				continue;
			int next = board[ny][nx] + visited[y][x];
			if (visited[ny][nx] == -1 || visited[ny][nx] > next)
			{
				visited[ny][nx] = next;
				q.push({ ny, nx });
			}
		}
	}
	// for (int y = 0; y < board.size(); ++y)
	// {
	// 	for (int x = 0; x < board[y].size(); ++x)
	// 		cout << visited[y][x] << " ";
	// 	cout << endl;
	// }
	return (visited[board.size() - 1][board[0].size() - 1]);
}

int main()
{
	string input;
	while (1)
	{
		cin >> input;
		if (cin.eof())
			break;

		vector<int> tmp;
		for (auto c : input)
		{
			tmp.push_back(c - '0');
		}
		board.push_back(tmp);
	}

	// for (auto line : board)
	// {
	// 	for (auto n : line)
	// 		cout << n << " ";
	// 	cout << endl;
	// }

	cout << endl << bfs() << endl;
	return (0);
}
