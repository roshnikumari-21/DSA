// On each day, you may decide to buy and/or sell the stock.
// You can only hold at most one share of the stock at any time.
//  However, you can buy it then immediately sell it on the same day.

// memoization code________tc=O(2n)________________sc=O(n)____________________
//top down approach_

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int f(int ind, int buy, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (ind == n)
        {
            if (buy == 1)     //transaction completed
                return 0;
            else
                return -1e9;
        }
        
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 1)
            return dp[ind][buy] = max(-arr[ind] + f(ind + 1, 0, arr, dp), f(ind + 1, 1, arr, dp));
        else
            return dp[ind][buy] = max(arr[ind] + f(ind + 1, 1, arr, dp), f(ind + 1, 0, arr, dp));
    }
    int maxProfit(vector<int> &arr)
    {
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, arr, dp);
    }
};

// tabulation code________tc=O(n)______________sc=O(1)___________________________________

class Solution
{
public:
    int n;

    int maxProfit(vector<int> &arr)
    {
        n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][1] = 0;
        dp[n][0] = -1e9;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int j = 0; j < 2; j++)
            {

                if (j == 1)
                    dp[ind][j] = max(-arr[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                else
                    dp[ind][j] = max(arr[ind] + dp[ind + 1][1], dp[ind + 1][0]);
            }
        }

        return dp[0][1];
    }
};


//one more method_____without dp_______________________


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                ans += (prices[i + 1] - prices[i]);
            }
        }

        return ans;
    }
};
