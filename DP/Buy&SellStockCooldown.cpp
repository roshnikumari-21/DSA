#include <bits/stdc++.h>
using namespace std;

//After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

// memoization___________________________________________________________________

class Solution
{
public:
    int f(int ind, int buy, vector<int> &arr, int n, vector<vector<int>> &dp)
    {
        if (ind >= n)
        {
            if (buy == 1)
                return 0;
            else
                return -1e9;
        }
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 1)
            return dp[ind][buy] = max(-arr[ind] + f(ind + 1, 0, arr, n, dp),
                                      f(ind + 1, 1, arr, n, dp));
        else
            return dp[ind][buy] = max(arr[ind] + f(ind + 2, 1, arr, n, dp),
                                      f(ind + 1, 0, arr, n, dp));
}

    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, arr, n, dp);
    }
};



// tabulation______________________________________________________________________

class Solution
{
public:
    int maxProfit(vector<int> &pri)
    {
        int n = pri.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 0)
                {
                    dp[ind][buy] =
                        max(-pri[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }

                else
                {
                    dp[ind][buy] =
                        max(pri[ind] + dp[ind + 2][0], dp[ind + 1][1]);
                }
            }
        }

        return dp[0][0];
    }
};