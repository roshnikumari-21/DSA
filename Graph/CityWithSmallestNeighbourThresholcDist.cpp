// application of Floyd warshall

// Return the city with the smallest number of cities that are reachable through some path
//  and whose distance is at most distanceThreshold, If there are multiple such cities,
//   return the city with the greatest number.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int thres)
    {
        vector<vector<int>> adjmat(n, vector<int>(n, INT_MAX));
        for (auto it : edges)
        {
            adjmat[it[0]][it[1]] = it[2];
            adjmat[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
            adjmat[i][i] = 0;    //digonal elements

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adjmat[i][k] == INT_MAX || adjmat[k][j] == INT_MAX)
                        continue;
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
                }
            }
        }

        int cityNo = -1;
        int cnt = 0, mini = n;
        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            for (int k = 0; k < n; k++)    //traversing each col of this row
            {
                if (adjmat[i][k] <= thres)
                    cnt++;
            }

            if (cnt <= mini)
            {
                mini = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};