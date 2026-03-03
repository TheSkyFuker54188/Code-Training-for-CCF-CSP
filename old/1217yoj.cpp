#include <iostream>
#include <vector>

using namespace std;

// DFS 方法遍历岛屿
void dfs(vector<vector<int>> &grid, int x, int y, int m, int n)
{
    // 检查边界和是否为陆地
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
    {
        return;
    }

    // 标记为已访问
    grid[x][y] = 0;

    // 遍历上下左右四个方向
    dfs(grid, x - 1, y, m, n);
    dfs(grid, x + 1, y, m, n);
    dfs(grid, x, y - 1, m, n);
    dfs(grid, x, y + 1, m, n);
}

int numIslands(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    // 遍历每个单元格
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 1)
            { // 找到一个新的岛屿
                ++count;
                dfs(grid, i, j, m, n); // 使用 DFS 标记整个岛屿
            }
        }
    }

    return count;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }

    cout << numIslands(grid) << endl;

    return 0;
}
