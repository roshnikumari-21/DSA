// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1


// Metric___Value
// Time Complexity	O(n × tar)
// Space Complexity	O(n × tar)


//memoization_____________________________________

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int f(int ind, vector<int> &arr, int tar, vector<vector<int>> &dp)
    {
        if (tar == 0)
            return 0;
        if (ind < 0)
            return 1e9;

        if (dp[ind][tar] != -1)
            return dp[ind][tar];


        int take = 1e9;
        if (tar >= arr[ind])
            take = 1 + f(ind, arr, tar - arr[ind], dp);
        int ntake = f(ind - 1, arr, tar, dp);
        return dp[ind][tar] = min(take, ntake);
    }

    
    int coinChange(vector<int> &arr, int tar)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        int ans = f(n - 1, arr, tar, dp);
        if (ans == 1e9)
            return -1;
        else
            return ans;
    }
};

//tabulation_________tc=O(n*tar)_________________________________________



class Solution {
public:
    int coinChange(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));

        for (int ta = 0; ta <= tar; ta++) {
            if (ta % arr[0] == 0)
                dp[0][ta] = ta / arr[0];
            else
                dp[0][ta] = 1e9;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int ta = 0; ta <= tar; ta++) {

                int take = 1e9;
                if (ta >= arr[ind])
                    take = 1 + dp[ind][ta - arr[ind]];
                int ntake = dp[ind - 1][ta];
                dp[ind][ta] = min(take, ntake);
            }
        }

        int ans = dp[n - 1][tar];

        if (ans == 1e9)
            return -1;
        else
            return ans;
    }
};