// using priority queue-----> take diff , and row, col
// kind of dijkstra algorithm

//  will  come backk... for suree...

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &hei)
    {
        int n = hei.size();
        int m = hei[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        //using a min pq  (dif,(row,col))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));    //dis 2d matrix, initialized with infinity...
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;
            if (row == n - 1 && col == m - 1)
                return dis;               //reached goal return the min. dif
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0)
                {
                    int nweffort = max(abs(hei[nrow][ncol] - hei[row][col]), dis);
                    if (nweffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = nweffort;
                        pq.push({nweffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};