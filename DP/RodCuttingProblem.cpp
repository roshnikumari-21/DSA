// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost
//  associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.


#include <bits/stdc++.h>
using namespace std;




class Solution {
    public:
        int f(int ind, int n, int price[], int len,vector<vector<int>>&dp) {
            // Base cases
            if (len == 0) return 0; // No more length to cut
            if (ind == n || len < 0) return -1e9; // Invalid case or out of bounds
            
            // Recursive choices: take or not take
            if(dp[ind][len]!=-1) return dp[ind][len];
            int take = -1e9;
            if (len >= ind + 1) // Only take if current piece can be cut
                take = price[ind] + f(ind, n, price, len - (ind + 1),dp);
            int ntake = f(ind + 1, n, price, len,dp);
            
            return  dp[ind][len]= max(take, ntake); // Maximize profit
        }
        
        int cutRod(int price[], int n) {
            vector<vector<int>> dp(n, vector<int>(n+1, -1));
            return f(0, n, price, n,dp); // Correct call with full length
        }
    };

