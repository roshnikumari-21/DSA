//Mcm dp---->solve a problem in a particular pattern


// Input: arr[] = [2, 1, 3, 4]--->first(1*3 and 3*4 ) then remaining
// Output: 20


// Metric	Value
// Time Complexity	O(n³)
// Space Complexity	O(n²)--->dp array

#include <bits/stdc++.h>
using namespace std;

//memoization___________________________________

class Solution
{
public:
    int n;

    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (j - i < 2)   //i==j-1, i and j are adjacent
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int val = 1e9;
        for (int k = i + 1; k < j; k++)
        {
            val = min(val, (arr[i] * arr[j] * arr[k]) + solve(i, k, arr, dp) + solve(k, j, arr, dp));
        }

        return dp[i][j] = val;
    }


    int matrixMultiplication(vector<int> &arr)
    {
        n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, arr, dp);
    }
};



// tabulation_____________________________________________________________

class Solution
{
public:
    int n;

    int matrixMultiplication(vector<int> &arr)
    {
        // code here
        n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i == j - 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int val = 1e9;
                    for (int k = i + 1; k < j; k++)
                    {
                        val = min(val, (arr[i] * arr[j] * arr[k]) + dp[i][k] + dp[k][j]);
                    }

                    dp[i][j] = val;
                }
            }
        }

        return dp[0][n - 1];
    }
};
