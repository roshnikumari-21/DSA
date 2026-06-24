#include <bits/stdc++.h>
using namespace std;
//3d dp
// fixed starting point and variable ending point
// take 4 parameters i1,j1,i2,j2

// two types of base casses---> one out of boundary, one reached destination

// return -1e8 not INT_MIN bcoz  when it get added with some inteeger , might overflow

// move both alice and bob simultaneoulsy

// only recursion tc=O(3^n * 3^n) , sc=O(N)

// memoization code
// tc=O(m*n*n)   sc=O(n*m*m)+O(N)-->auxilliary stack space of recursion

class Solution
{
public:
    int f(int i, int j, int k, int n, int m, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
    {

        if (j < 0 || j >= m || k < 0 || k >= m)    // out of bound
            return -1e9;
        if (i == n - 1)              //destination
        {

            if (j == k)
                return arr[i][j];
            else
                return arr[i][j] + arr[i][k];
        }
        
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int maxi = 0;

        for (int d1 = -1; d1 < 2; d1++)
        {
            for (int d2 = -1; d2 < 2; d2++)
            {
                if (j == k) // equal pr h to one time add
                    maxi = max(maxi, arr[i][j] + f(i + 1, j + d1, k + d2, n, m, arr, dp));
                else // otherwise 2 baar add hoga
                    maxi = max(maxi, arr[i][j] + arr[i][k] + f(i + 1, j + d1, k + d2, n, m, arr, dp));
            }
        }

        return dp[i][j][k] = maxi;
    }


    int solve(int n, int m, vector<vector<int>> &arr)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, n, m, arr, dp);
    }
};



//__________tabulation________________________________________________________

class Solution
{
public:
    
    int solve(int n, int m, vector<vector<int>> &arr)
    {

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                    dp[n - 1][i][j] = arr[n - 1][i];
                else
                    dp[n - 1][i][j] = arr[n - 1][i] + arr[n - 1][j];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    int maxi = 0;

                    for (int d1 = -1; d1 < 2; d1++)
                    {
                        for (int d2 = -1; d2 < 2; d2++)
                        {
                            if (j + d1 >= 0 && j + d1 < m && k + d2 >= 0 && k + d2 < m)
                            {
                                if (j == k)
                                    maxi = max(maxi, arr[i][j] + dp[i + 1][j + d1][k + d2]);
                                else
                                    maxi = max(maxi, arr[i][j] + arr[i][k] + dp[i + 1][j + d1][k + d2]);
                            }
                        }
                    }

                    dp[i][j][k] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};
