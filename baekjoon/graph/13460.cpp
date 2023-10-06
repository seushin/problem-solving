/*
 * https://www.acmicpc.net/problem/13460
 * 구슬 탈출 2
 */

#include <iostream>
#include <queue>

#define MAX_SIZE 10
#define MAX_TRY 10

enum class Tile : char
{
	wall = '#',
	empty = '.',
	red = 'R',
	blue = 'B',
	hole = 'O',
};

struct Ball
{
	int y;
	int x;

	bool operator==(const Ball &p)
	{
		return y == p.y && x == p.x;
	}
};

struct Game
{
	Ball red;
	Ball blue;
	int count;
};

// down, up, right, left
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int N, M;
Tile board[MAX_SIZE][MAX_SIZE];

int solve(Ball red, Ball blue)
{
	std::queue<Game> q;

	q.push(Game{red, blue, 0});
	while (!q.empty())
	{
		Game game = q.front();

		q.pop();
		if (game.count >= MAX_TRY)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			Ball red = game.red;
			Ball blue = game.blue;
			int count = game.count + 1;

			while (board[blue.y + dy[i]][blue.x + dx[i]] != Tile::wall)
			{
				blue.y += dy[i];
				blue.x += dx[i];

				if (board[blue.y][blue.x] == Tile::hole)
					goto next_dir;
			}
			while (board[red.y + dy[i]][red.x + dx[i]] != Tile::wall)
			{
				red.y += dy[i];
				red.x += dx[i];

				if (board[red.y][red.x] == Tile::hole)
					return count;
			}

			if (red == blue)
			{
				switch (i)
				{
				case 0: // down
					game.red.y < game.blue.y ? --red.y : --blue.y;
					break;
				case 1: // up
					game.red.y > game.blue.y ? ++red.y : ++blue.y;
					break;
				case 2: // right
					game.red.x < game.blue.x ? --red.x : --blue.x;
					break;
				case 3: // left
					game.red.x > game.blue.x ? ++red.x : ++blue.x;
					break;
				}
			}

			if (red == game.red && blue == game.blue)
				continue;

			q.push(Game{red, blue, count});

		next_dir:
			continue;
		}
	}

	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	Ball red, blue;

	std::cin >> N >> M;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			char c;
			Tile &tile = board[y][x];

			std::cin >> c;
			tile = static_cast<Tile>(c);

			if (tile == Tile::red)
				red = Ball{y, x};
			else if (tile == Tile::blue)
				blue = Ball{y, x};
		}
	}

	std::cout << solve(red, blue) << std::endl;

	return 0;
}
