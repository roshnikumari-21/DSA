// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
//basically return nodes which are trapped inside grid

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis,
             int drow[], int dcol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < n && nrow >= 0 && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 &&
                mat[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, mat, vis, drow, dcol);
            }
        }
    }

    
    int numEnclaves(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int sum = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum += mat[i][j];
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //first row pr dfs
        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 1 && vis[0][i] == 0)
            {
                dfs(0, i, mat, vis, drow, dcol);
            }
        }
         //last row pr dfs
        for (int i = 0; i < m; i++)
        {
            if (mat[n - 1][i] == 1 && vis[n - 1][i] == 0)
            {
                dfs(n - 1, i, mat, vis, drow, dcol);
            }
        }

         //first col pr dfs
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 1 && vis[i][0] == 0)
            {
                dfs(i, 0, mat, vis, drow, dcol);
            }
        }

         //last col pr dfs
        for (int i = 0; i < n; i++)
        {
            if (mat[i][m - 1] == 1 && vis[i][m - 1] == 0)
            {
                dfs(i, m - 1, mat, vis, drow, dcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum2 += vis[i][j];
            }
        }
        return sum - sum2;
    }
};