// everyone itself is an lis  ...with an count of 1

//tc=O(n^2)
//sc=O(N)+O(N)--->O(N)



#include <bits/stdc++.h>
using namespace std;



int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);  
    vector<int> cnt(n, 1); 
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev]; // Update longest length
                cnt[i] = cnt[prev];   // Inherit count of previous
            }
            else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
            {
                cnt[i] += cnt[prev]; // Increase count
            }
        }
        maxi = max(maxi, dp[i]); // Track maximum length
    }


    
    int nos = 0; // Total count of longest increasing subsequences
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            nos += cnt[i]; // Sum counts for the longest subsequences
        }
    }

    return nos; // Return the total count
}