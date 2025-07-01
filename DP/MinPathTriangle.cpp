#include <bits/stdc++.h>
using namespace std;

//tc=O(m^2)______________ sc=O(m^2)


class Solution
{
public:
    int f(int i, int j, int m, vector<vector<int>> &dp, vector<vector<int>> &arr)
    {
        if (i >= m || j > i)
            return 1e9;  //not possible

        if (i == m - 1)
        {
            return arr[i][j];
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        int right = arr[i][j] + f(i + 1, j + 1, m, dp, arr);
        int down = arr[i][j] + f(i + 1, j, m, dp, arr);
        return dp[i][j] = min(right, down);
    }

    int minimumTotal(vector<vector<int>> &arr)
    {
        int m = arr.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));
        return f(0, 0, m, dp, arr);
    }
};



//tabulation______________________________________________________________________




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int m = arr.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < m; i++) {
            dp[m][i] = 1e9;
        }

        for (int i = 0; i < m; i++) {
            dp[m - 1][i] = arr[m - 1][i];
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int right = arr[i][j] + dp[i + 1][j + 1];
                int down = arr[i][j] + dp[i + 1][j];
                dp[i][j] = min(right, down);
            }
        }

        return dp[0][0];
    }
};