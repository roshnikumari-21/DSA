#include <bits/stdc++.h>
using namespace std;

//codestorywithMIK
//bfs

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


//using dijstra___________________________


class Solution {
public:
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 0 || grid[0][0] == 1)
            return -1;

        vector<vector<int>> res(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});
        res[0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 8; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && res[nr][nc] > dist + 1) {
                    res[nr][nc] = dist + 1;
                    pq.push({dist + 1, {nr, nc}});
                }
            }
        }
        if (res[n - 1][n - 1] == 1e9)
            return -1;

        return res[n - 1][n - 1] + 1;
    }
};