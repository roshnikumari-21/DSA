#include <bits/stdc++.h>
using namespace std;


//Find the maximum profit you can achieve. You may complete at most two transactions.

class Solution
{
public:
    int f(int ind, int buy, vector<int> &arr, int n, vector<vector<vector<int>>> &dp, int cnt)
    {
        if (cnt == 2)
            return 0;   //only max 2 transaction
      

        if (ind == n && cnt <= 2 && buy == 1)
            return 0;    //transaction completed
        if (ind == n)
            return -1e9;

        if (dp[ind][buy][cnt] != -1)
            return dp[ind][buy][cnt];


        if (buy == 1)
            return dp[ind][buy][cnt] = max(-arr[ind] + f(ind + 1, 0, arr, n, dp, cnt), f(ind + 1, 1, arr, n, dp, cnt));
        else
            return dp[ind][buy][cnt] = max(arr[ind] + f(ind + 1, 1, arr, n, dp, cnt + 1), f(ind + 1, 0, arr, n, dp, cnt));
    }

    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, arr, n, dp, cnt);
    }
};


//tabulation__________________________________________________________________

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 1; k < 3; k++) {
                    if (j == 1)
                        dp[i][j][k] =
                            max(-arr[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                    else
                        dp[i][j][k] =
                            max(arr[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
                }
            }
        }

        return dp[0][1][2];
    }
};