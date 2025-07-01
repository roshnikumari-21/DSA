#include <bits/stdc++.h>
using namespace std;



//count the unique paths

//memoization__________________________________________________
//tc=O(n*m)  sc=O(n-1+m-1+ n*m)--->recursion+dp array


class Solution
{
public:
    int f(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return 0;
        
        if (i == m - 1 && j == n - 1)
        {
            return 1;   //found a path
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = f(i, j + 1, m, n, dp);
        int down = f(i + 1, j, m, n, dp);
        return dp[i][j] = right + down;
    }

    
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, dp);
    }
};


//tabulation________________________________________________
//tc=O(n*m)           sc=O(n*m)

class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
            dp[m - 1][n - 1] = 1;
    
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1)
                        continue;
    
                    int right = dp[i][j + 1];
                    int down = dp[i + 1][j];
                    dp[i][j] = right + down;
                }
            }
    
            return dp[0][0];
        }
    };


    //__________tc=O(r)    sc=O(1)______________________________


    //formula is (n+m-2)C(m-1)  or (n+m-2)C(n-1) ..

class Solution {
public:
    int help(int n, int r) {
        int res = 1;
        for (int i = 1; i <= r; i++) {
            res *= n;
            res /= i;
            n--;
        }
        return res;
    }
    int uniquePaths(int m, int n) { return help(n + m - 2, m - 1); }
};