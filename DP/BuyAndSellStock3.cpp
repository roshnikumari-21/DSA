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