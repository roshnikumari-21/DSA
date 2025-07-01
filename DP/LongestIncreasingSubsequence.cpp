// Input: nums = [0,1,0,3,2,3]
// Output: 4  (length of lis)

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4

// it has to be increasing not equal......

#include <bits/stdc++.h>
using namespace std;
// only recurrence-->tc=O(2^n)

// memoization code________tc=O(n*n)___________sc=O(n*n)+O(n)___________________________
// co-ordinate shift will be applied here, bcoz pre is from -1 to n-1...



class Solution
{
public:
    int n;
    int f(int ind, int pre, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == n)    return 0;            

        if (dp[ind][pre + 1] != -1)
            return dp[ind][pre + 1];
            
        int take = 0;
        if (pre == -1 || nums[ind] > nums[pre])
            take = 1 + f(ind + 1, ind, nums, dp);
        int ntake = f(ind + 1, pre, nums, dp);
        return dp[ind][pre + 1] = max(take, ntake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp); // pre is index of previous element taken
    }
};



// tabulation code____________________sc = O(n*n)______________________________________________

class Solution
{
public:
    int n;

    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int pre = ind - 1; pre >= -1; pre--)
            {
                int take = 0;
                if (pre == -1 || nums[ind] > nums[pre])
                    take = 1 + dp[ind + 1][ind + 1]; // shift in pre ka index ...
                int ntake = dp[ind + 1][pre + 1];
                dp[ind][pre + 1] = max(take, ntake);
            }
        }
        return dp[0][0];
    }
};



//most optimal________________________________________________
//tc=O(N^2)   sc=O(N)

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);  // Initialize dp array with 1s
    int maxi = 1;

    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] < arr[i]) {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}
