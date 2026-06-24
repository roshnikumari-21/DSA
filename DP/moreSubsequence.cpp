#include <bits/stdc++.h>
using namespace std;

// You are given two strings 'A' and 'B' of length 'N' and 'M' respectively.
// Return the string that has more distinct subsequences, if both strings have the same number of distinct
//  subsequences, then return 'A'.

//duplicate wale jo use pehle sequence bnaye the, wo phir se bn jayenge....that's why
//0th index khali h...that's why it's extra index


// total subsequence is=2^n  (with duplicates)
// tc=O(N)   sc=O(1)



int count(string s)
{ // fxn to count distinct subsequence
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    map<char, int> mp;     //(char,ind)

    for (int i = 1; i < dp.size(); i++)      //indexing shift
    {
        dp[i] = 2 * dp[i - 1];
        char ch = s[i - 1];
        if (mp.find(ch) != mp.end())   //already char tha pehle
            dp[i] -= dp[mp[ch] - 1];
        mp[ch] = i;
    }

    return dp[n];
}

string moreSubsequence(int n, int m, string a, string b)
{
    int aa = count(a);
    int bb = count(b);
    if (aa >= bb)
        return a;
    else
        return b;
}