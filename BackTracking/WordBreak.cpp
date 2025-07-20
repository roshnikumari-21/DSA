// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true

//tc=O((n^2)*m), m is no. of words given in worddict
//sc=O(n)

//recursion+memoization

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(string s, vector<string> &word, int n, int ind, vector<int> &dp)
    {
        if (ind == n)
        {
            return true;
        }
        if (dp[ind] != -1)
            return dp[ind];

        for (int i = ind; i < n; i++)
        {
            string temp = s.substr(ind, i + 1 - ind);
            if (find(word.begin(), word.end(), temp) != word.end())  //O(m), m is no. of word in list
            {
                if (f(s, word, n, i + 1, dp))
                    return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    
    bool wordBreak(string s, vector<string> &word)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(s, word, n, 0, dp);
    }
};