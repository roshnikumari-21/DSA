#include <bits/stdc++.h>
using namespace std;

// tc=O(n)___________memoization___________

class Solution
{
public:
    int f(int i, int n, vector<int> &nums, vector<int> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i] + f(i + 2, n, nums, dp), f(i + 1, n, nums, dp));
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, n, nums, dp);
    }
};

// tabulation________tc=O(N)______________sc=O(n)__________

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }
};