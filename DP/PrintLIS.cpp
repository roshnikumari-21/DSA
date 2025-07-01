// using tabulation
// tc=O(N^2)
// just 1d dp
// dp[i]--->Signifies the longest increasing subsequence ending at index i

#include <bits/stdc++.h>
using namespace std;


void printLIS(int arr[], int n)
{
    vector<int> dp(n, 1);        // Initialize the dp array with 1s
    vector<int> previous(n, -1); // To track the indices of the LIS
    int maxi = 1;
    int lastIndex = 0; // To store the last index of the LIS

    
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                if (dp[i] < 1 + dp[prev])
                { // Update dp[i] only if we find a longer subsequence
                    dp[i] = 1 + dp[prev];
                    previous[i] = prev; // Track the previous index
                }
            }
        }
        
        if (maxi < dp[i])
        {
            maxi = dp[i];
            lastIndex = i; // Update the last index of the longest increasing subsequence
        }
    }

    // Reconstruct the LIS
    vector<int> lis;
    for (int i = lastIndex; i >= 0; i = previous[i])
    {
        lis.push_back(arr[i]);
        if (previous[i] == -1)
            break; // Stop when there are no more elements in the LIS
    }

    // The LIS is reconstructed in reverse order, so reverse it
    reverse(lis.begin(), lis.end());

    // Print the LIS
    cout << "Longest Increasing Subsequence: ";
    for (int it : lis)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Length of LIS: " << maxi << endl;
}