#include <bits/stdc++.h>
using namespace std;

//with obstacles


class Solution
{
public:
    int n, m;
    int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &arr)
    {
        if (i >= m || j >= n)
            return 0;
        if (arr[i][j] == 1)
            return 0; // this path can't be considered

        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = f(i, j + 1, dp, arr);
        int down = f(i + 1, j, dp, arr);
        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &arr)
    {
        m = arr.size();
        n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, dp, arr);
    }
};