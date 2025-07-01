#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    const int MOD = 1e9 + 7;

    int f(int ind, int tar, int arr[], vector<vector<int>> &dp, int n)
    {
        if (tar == 0)
            return 1; // Found a valid subset
        if (ind == n)
            return 0; // No more elements to consider

        if (dp[ind][tar] != -1)
            return dp[ind][tar];

        int include = 0;
        if (tar >= arr[ind])
        {
            include = f(ind + 1, tar - arr[ind], arr, dp, n) % MOD;
        }
        int exclude = f(ind + 1, tar, arr, dp, n) % MOD;

        return dp[ind][tar] = (include + exclude) % MOD;
    }



    int powerOfTwo(int count, int mod)
    {
        int result = 1;
        for (int i = 0; i < count; ++i)
        {
            result = (result * 2) % mod;
        }
        return result;
    }



    int perfectSum(int arr[], int n, int sum)
    {
        int countZeros = 0;

        // Separate zeros from the array
        vector<int> nonZeroElements;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                countZeros++;
            else
                nonZeroElements.push_back(arr[i]);
        }

        // Initialize dp for non-zero elements
        vector<vector<int>> dp(nonZeroElements.size(), vector<int>(sum + 1, -1));

        // Count subsets using non-zero elements only
        int subsetsWithoutZeros = f(0, sum, nonZeroElements.data(), dp, nonZeroElements.size());

        // Multiply result by 2^countZeros to account for subsets with zeros
        int result = (subsetsWithoutZeros * powerOfTwo(countZeros, MOD)) % MOD;

        return result;
    }
};
