// find number of islands
// can use a bfs


//tc=O(n*m)
//sc=O(n*M)+queue taking at max O(n*m)

#include <vector>
#include <queue>

using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    // Directions for moving up, down, left, and right
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Explore neighbors
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    if (n == 0)
        return 0;


    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grid[row][col] == '1' && !vis[row][col])
            {
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }

    return cnt;
}