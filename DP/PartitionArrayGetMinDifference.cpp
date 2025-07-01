// we want difference as minimal as possible

#include <bits/stdc++.h>
using namespace std;

//dp[i][j] signifies that target j is possilbe or not till index i



class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        long long n = nums.size();
        long long sum = 0;
        for (long long i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<vector<long long>> dp(n, vector<long long>(sum + 1, 0));
        for (long long i = 0; i < n; i++)
        {
            dp[i][0] = 1;     //first col, target 0 is achievable always
        }
        if (nums[0] <= sum)
            dp[0][nums[0]] = 1;

        for (long long i = 1; i < n; i++)
        {
            for (long long j = 1; j <= sum; j++)
            {
                long long nt = dp[i - 1][j];
                long long t = 0;
                if (nums[i] <= j)
                    t = dp[i - 1][j - nums[i]];
                dp[i][j] = (t | nt);
            }
        }

        //computing min difference
        long long mini = 1e9;
        for (long long i = 0; i <= sum / 2; i++)
        {
            if (dp[n - 1][i] == 1)
            {
                long long a = i;     //i is the target
                long long b = sum - i;

                mini = min(mini, abs(a - b));
            }
        }
        return mini;
    }
};