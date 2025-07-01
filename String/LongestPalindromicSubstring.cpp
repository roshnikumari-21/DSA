#include <bits/stdc++.h>
using namespace std;


//tc=O(n^3)

class Solution
{
public:
    bool ispali(string &s, int i, int j)
    {
        if (i >= j)
            return true;
        if (s[i] == s[j])
            return ispali(s, i + 1, j - 1);
        return false;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        int i = 0, j = 0;
        vector<string> v;
        string ans;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {               
                if (ispali(s, i, j))
                {
                    if ((j - i + 1) > maxi)
                    {
                        ans = s.substr(i, j - i + 1);
                        maxi = j - i + 1;
                    }
                }
            }
        }

       
        return ans;
    }
};



//with dp and memoization___________________________________________________________________________________
//bs palindrome ke liye dp

// Metric	Complexity
// Time	O(n²)
// Space	O(n²)



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispali(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = ispali(s, i + 1, j - 1, dp);

        return dp[i][j] = false;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        string ans = "";
        int maxi = -1;

        // Initialize memoization table with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (ispali(s, i, j, dp))
                {
                    if ((j - i + 1) > maxi)
                    {
                        ans = s.substr(i, j - i + 1);
                        maxi = j - i + 1;
                    }
                }
            }
        }

        return ans;
    }
};


