#include <vector>
using namespace std;

class Solution {
public:
    const int dy[4] = { 1, -1, 0, 0 };
    const int dx[4] = { 0, 0, 1, -1 };

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[y].size(); ++x)
            {
                if (grid[y][x] == 1)
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if (ny < 0 || ny > grid.size() - 1 ||
                            nx < 0 || nx > grid[y].size() - 1)
                            perimeter++;
                        else if (grid[ny][nx] == 0)
                            perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};
