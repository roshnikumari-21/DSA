// A falling path starts at any element in the first row and chooses the element
// in the next row that is either directly below or diagonally left/right

// variable starting point......variable ending point

#include <bits/stdc++.h>
using namespace std;


//memoization_________tle_________(top-down)_______________________

class Solution
{
public:
    int n;

    int solve(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &dp)
    {
        if (row == n - 1)
            return mat[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int left = INT_MAX, right = INT_MAX, down = INT_MAX;
        if (col > 0 && row < n - 1)      //left diag
            left = mat[row][col] + solve(mat, row + 1, col - 1, dp);
        if (row < n - 1)                 //down
            down = mat[row][col] + solve(mat, row + 1, col, dp);
        if (col < n - 1)                     //right diag
            right = mat[row][col] + solve(mat, row + 1, col + 1, dp);
        return dp[row][col] = min({left, right, down});
    }


    int minFallingPathSum(vector<vector<int>> &mat)
    {
        n = mat.size();

        int mini = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int col = 0; col < n; col++)
        {           
            mini = min(mini, solve(mat, 0, col, dp));
        }

        return mini;
    }
};


//tabulation____________(bottom-up)________________________________________



class Solution {
    public:
        int n;
    
        int minFallingPathSum(vector<vector<int>>& mat) {
            n = mat.size();
    
            int mini = INT_MAX;
    
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
            for (int j = 0; j < n; j++) {
                dp[n - 1][j] = mat[n - 1][j]; // last row fill dp table
            }
    
            for (int row = n - 2; row >= 0; row--) {
                for (int col = 0; col < n; col++) {
    
                    int left = INT_MAX, right = INT_MAX, down = INT_MAX;
                    if (col < n - 1 && row < n - 1)
                        left = mat[row][col] + dp[row + 1][col + 1];
                    if (row < n - 1)
                        down = mat[row][col] + dp[row + 1][col];
                    if (col > 0 && row < n - 1)
                        right = mat[row][col] + dp[row + 1][col - 1];
                    dp[row][col] = min({left, right, down});
                }
            }
    
            for (int col = 0; col < n; col++) {
                mini = min(mini, dp[0][col]);
            }
    
            return mini;
        }
    };