// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two cells sharing a common edge is 1.

//bfs algorithm


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0)); //not hampering the original matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        queue<pair<pair<int, int>, int>> q;   //(row,col, (dis))
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});  //push and mark it visited
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[row][col] = dis;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && vis[nrow][ncol] == 0)
                {
                    q.push({{nrow, ncol}, dis + 1});  //push  and mark it visited
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return ans;
    }
};