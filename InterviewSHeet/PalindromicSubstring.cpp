#include <bits/stdc++.h>
using namespace std;

//with memo+recursion______________________________
//tc=O(n^2)        sc=O(n^2)


class Solution {
public:
   bool check(int i,int j,string s,vector<vector<int>>&dp){    
    if(i>j) return 1;
    if(s[i]!=s[j]) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    else return dp[i][j]=check(i+1,j-1,s,dp);
   }
    int countSubstrings(string s) {
        int ans;
        int cnt=0;
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,s,dp)) cnt++;
            }
        }
        return cnt;
    }
};

//________________________________________________


