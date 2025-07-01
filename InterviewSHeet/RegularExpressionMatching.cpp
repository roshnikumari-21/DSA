//codewithMIK

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int n, m;

    bool solve(int i, int j, string &s, string &p,vector<vector<int>>&dp) {
        if (i == n) {
            if (j == m)
                return true;
            else if(j+1<m && p[j+1]=='*') return solve(i,j+2,s,p,dp);
               else  return false;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        bool fir = false;
        if (i < n   && (p[j] == s[i] || p[j] == '.')) {
            fir = true;
        }

        if (j + 1 < m && p[j + 1] == '*') {
            bool take = false;
            if (fir)
                take = solve(i + 1, j, s, p,dp);
            bool ntake = solve(i, j + 2, s, p,dp);
            return dp[i][j]= (take || ntake);
        }

        else if (fir)
            return dp[i][j]= solve(i + 1, j + 1, s, p,dp);
        return dp[i][j]= false;
    }

    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0, 0, s, p,dp);
    }
};