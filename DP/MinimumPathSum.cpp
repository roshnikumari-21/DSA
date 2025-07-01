// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
//  which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

#include <bits/stdc++.h>
using namespace std;

//memoization_________tc=O(m*n)_________________sc=O(m*n)_________________________________

class Solution {
    public:
      int n,m;
        int f(int i, int j,  vector<vector<int>>& dp,
              vector<vector<int>>& arr) {
            if (i >= m || j >= n)
                return 1e9;   //not correct path
           
            if (i == m - 1 && j == n - 1) {    
                return arr[i][j];   //reached bottom right
            }
            
            if (dp[i][j] != -1)
                return dp[i][j];

            int right = arr[i][j] + f(i, j + 1,  dp, arr);
            int down = arr[i][j] + f(i + 1, j,  dp, arr);
            return dp[i][j] = min(right, down);
        }
    
        int minPathSum(vector<vector<int>>& arr) {
             m = arr.size();
             n = arr[0].size();
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return f(0, 0, dp, arr);
        }
    };



//tabulation______________________________________can ignore_____________________________________________________
//if u are confused ....print the dp table
//tc,sc=O(m*n)

class Solution {
    public:
        int minPathSum(vector<vector<int>>& arr) {
            int m = arr.size();
            int n = arr[0].size();
            
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            // Fill the DP table bottom-up
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 && j == 0)
                        dp[i][j] = arr[i][j];  // Start position
                    else {
                        int fromTop = (i > 0) ? dp[i - 1][j] : 1e9;
                        int fromLeft = (j > 0) ? dp[i][j - 1] : 1e9;
                        dp[i][j] = arr[i][j] + min(fromTop, fromLeft);
                    }
                }
            }
    
            return dp[m - 1][n - 1];  // Bottom-right corner contains the answer
        }
    };
    


    //_________real tabulation______bottom up_______________________________


    class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) { // last col
            dp[i][n] = 1e9;
        }
        for (int j = 0; j < n; j++) { // last row
            dp[m][j] = 1e9;
        }

        dp[m - 1][n - 1] = arr[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                int right = arr[i][j] + dp[i][j + 1];
                int down = arr[i][j] + dp[i + 1][j];
                dp[i][j] = min(right, down);
            }
        }

        return dp[0][0];
    }
};