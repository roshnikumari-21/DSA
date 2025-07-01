#include <bits/stdc++.h>
using namespace std;

//sort the array bcoz, subset does not follow any order

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, start = 0;
        for (int i = 0; i < n; i++)
            hash[i] = i;
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi) 
            {
                maxi = dp[i];
                start = i;
            }
        }

        while (hash[start] != start)   //track the answers
        {
            ans.push_back(nums[start]);
            start = hash[start];
        }
        ans.push_back(nums[start]);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};