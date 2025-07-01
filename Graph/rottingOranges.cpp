// Return the minimum number of minutes that must elapse until no cell has a fresh orange.
// If this is impossible, return -1.

//tc=

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;        //  (row,col,time)

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int time = 0;           //note it

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t); // Update the maximum time

            // Process all four directions
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    grid[nrow][ncol] = 2;      // Mark the orange as rotten
                }
            }
        }

        // Check if any fresh oranges are left
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};