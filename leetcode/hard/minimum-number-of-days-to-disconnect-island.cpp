/*
 * https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minDays(vector<vector<int> > &grid)
	{
		if (isDisconnected(grid))
			return 0;

		if (canDisconnectForOneDay(grid))
			return 1;
		else
			return 2;
	}

	int canDisconnectForOneDay(vector<vector<int> > &grid)
	{
		if (grid.size() == 1 && grid[0].size() == 1)
			return 1;

		const int dx[] = {1, -1, 0, 0, 0};
		const int dy[] = {0, 0, 1, -1, 0};

		for (int y = 0; y < grid.size(); ++y)
		{
			for (int x = 0; x < grid[y].size(); ++x)
			{
				if (grid[y][x] == 0)
				{
					for (int i = 0; i < 4; ++i)
					{
						int tx = x + dx[i];
						int ty = y + dy[i];

						if (tx < 0 || tx >= grid[0].size() || ty < 0 || ty >= grid.size())
							continue;
						if (grid[ty][tx] == 1)
						{
							for (int j = 0; j < 5; ++j)
							{
								int nx = tx + dx[j];
								int ny = ty + dy[j];

								if (nx < 0 || nx >= grid[0].size() || ny < 0 || ny >= grid.size())
									continue;
								if (grid[ny][nx] == 1)
								{
									grid[ny][nx] = 0;
									if (isDisconnected(grid))
										return 1;
									grid[ny][nx] = 1;
								}
							}
						}
					}
				}
			}
		}
		return 0;
	}

	bool isDisconnected(vector<vector<int> > grid)
	{
		int count = 0;

		for (int y = 0; y < grid.size(); ++y)
		{
			for (int x = 0; x < grid[y].size(); ++x)
			{
				if (grid[y][x] == 1)
				{
					count++;
					removeIsland(grid, x, y);
				}
			}
		}
		return count != 1;
	}

	void removeIsland(vector<vector<int> > &grid, int x, int y)
	{
		if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] == 0)
			return;

		grid[y][x] = 0;
		removeIsland(grid, x + 1, y);
		removeIsland(grid, x - 1, y);
		removeIsland(grid, x, y + 1);
		removeIsland(grid, x, y - 1);
	}
};
