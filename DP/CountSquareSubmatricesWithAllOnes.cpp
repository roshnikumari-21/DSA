// brute--->check for every cell, try to expand it

// optimal aproach
// dp[i][j]----->indicates how many squares  are ending at right bottom ate i,j


//tc=O(N*M)             sc=O(N*M)


#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int countSquares(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = mat[i][j];     //copy the mat to dp
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (dp[i][j] == 1)
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += dp[i][j];
            }
        }

        return sum;
    }
};