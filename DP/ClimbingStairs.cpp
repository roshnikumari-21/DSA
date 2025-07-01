// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 #include <bits/stdc++.h>
 using namespace std;
 

 //memoization__________________________________________________________


 class Solution {
    public:
    
        int f(int i,int n, vector<int>&dp){
            if(i>n) return 0;
            if (i==n) return 1;
            if(dp[i]!=-1) return dp[i];
            return dp[i]= f(i+1,n,dp)+f(i+2,n,dp);    
        }

        
        int climbStairs(int n) {
             vector<int>dp(n,-1);
             int ans=f(0,n,dp);        
             return ans;
            
        }
    };

    //tabulation____________________________________________________


    class Solution {
        public:
            int climbStairs(int n) {
                vector<int> dp(n + 2, 0);
        
                dp[n] = 1;
        
                for (int i = n - 1; i >= 0; i--) {
        
                    dp[i] = dp[i + 1] + dp[i + 2];
                }
        
                return dp[0];
            }
        };