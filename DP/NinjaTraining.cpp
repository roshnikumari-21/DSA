#include <bits/stdc++.h>
using namespace std;


//some days, each day a particular task, no same taks on consecutive days
//only 3 aciviites are there

//tc=O(4*n) --->O(N)
//sc=O(n)


class Solution {
    public:
        int f(int ind, int last, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
            if (ind == n) return 0;
    
            if (dp[ind][last] != -1) return dp[ind][last];
    
            int maxi = 0;
            for (int i = 0; i <= 2; i++) {
                if (i != last) {
                    maxi = max(maxi, arr[ind][i] + f(ind + 1, i, n, arr, dp));
                }
            }
            return dp[ind][last] = maxi;
        }
    
        int maximumPoints(vector<vector<int>>& arr, int n) {
            vector<vector<int>> dp(n, vector<int>(4, -1));
            return f(0, 3, n, arr, dp);
        }
    };
    