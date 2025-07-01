#include <bits/stdc++.h>
using namespace std;

//you can use a dp...
//tc=O(N^2)   sc=O(N^2)


//find the number of jumps made to reach end ...

class Solution {
    public:
        int solve(int index, vector<int>& nums, vector<int>& dp) {
            int n = nums.size();
            if (index >= n - 1) return 0;
    
            if (dp[index] != -1) return dp[index];
    
            int mini = 1e9;
            for (int i = 1; i <= nums[index]; i++) {
                if (index + i < n) {
                    mini = min(mini, 1 + solve(index + i, nums, dp));
                }
            }
    
            return dp[index] = mini;
        }
    
        int jump(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, -1);
            return solve(0, nums, dp);
        }
    };
    




//using greedy
//tc=O(N) sc=O(1)

class Solution {
    public:
        int jump(vector<int>& nums) {
            int n=nums.size();
            int l=0,r=0,j=0;  //j=initial jumps
            while(r<n-1){
                int maxi=0;
                 for(int i=l; i<=r; i++){
                    maxi=max(maxi,i+nums[i]);
                 }
                 l=r+1;
                 r=maxi;
                j++;
            }
            return j;
        }
    };