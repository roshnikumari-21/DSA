#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0 || grid[0][0] == 1)
            return -1;
        vector<int> drow = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dcol = {0, 1, 1, 1, 0, -1, -1, -1};
        queue<pair<int, int>> q;    //(row,col)
        q.push({0, 0});
        int level = 1;      //note
        while (!q.empty())
        {
            int si = q.size();
            while (si--)       //note
            {
                int x = q.front().first;
                int y = q.front().second;
                if (x == n - 1 && y == n - 1)
                    return level;
                q.pop();
                for (int i = 0; i < 8; i++)
                {
                    int nx = drow[i] + x;
                    int ny = dcol[i] + y;
                    if (nx < n && nx >= 0 && ny < n && ny >= 0 && grid[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            level++;
        }

        return -1;
    }
};