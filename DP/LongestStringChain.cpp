#include <bits/stdc++.h>
using namespace std;


//tc=O(nlogn)->for sorting + O(n^2 * l)--->n is size of array and l is avg length of word



bool comp(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}




bool checkPossible(const string &s1, const string &s2)
{
    if (s1.size() != s2.size() + 1)   //s1 is bigger one
        return false;

    int first = 0, second = 0;
    while (first < s1.size())      //O(l)
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }

    // Return true if all characters of s2 were found in s1
    return (second == s2.size()  && first==s1.size());
}




int longestStrChain(vector<string> &arr)
{
    sort(arr.begin(), arr.end(), comp); // Sort the strings by their lengths
    int n = arr.size();
    vector<int> dp(n, 1); // Initialize DP array with 1
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkPossible(arr[i], arr[prev]) && dp[prev] + 1 > dp[i])
            {
                dp[i] = dp[prev] + 1; // Update length of longest chain
            }
        }
        maxi = max(maxi, dp[i]); // Update maximum length found
    }

    return maxi; // Return the maximum length of string chain
}