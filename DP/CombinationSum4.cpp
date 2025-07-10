#include <bits/stdc++.h>
using namespace std;


// Given an array of distinct integers nums and a target integer target, return the number of possible
//  combinations that add up to target.


//tc=O(N*Tar) 
//sc=O(tar) because of dp

class Solution
{
public:
    int f(int ind, vector<int> &nums, int tar, vector<int> &dp)
    {
        if (tar == 0)
            return 1;
        if (ind >= nums.size())
            return 0;
        int take = 0, ntake = 0;
        if (dp[tar] != -1)
            return dp[tar];
        if (nums[ind] <= tar)
            take = f(0, nums, tar - nums[ind], dp);

        ntake = f(ind + 1, nums, tar, dp);

        return dp[tar] = take + ntake;
    }
    int combinationSum4(vector<int> &nums, int tar)
    {

        int n = nums.size();

        vector<int> dp(tar + 1, -1);

        return f(0, nums, tar, dp);
    }
};