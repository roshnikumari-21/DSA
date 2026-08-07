#include <bits/stdc++.h>
using namespace std;



//here, the helper function is calculating no of subarray with sum <= goal
//tc=O(n) sc=O(1)
class Solution {
    public:
    
        int f(vector<int>& nums, int goal){
            if(goal<0) return 0;
            int l=0,r=0,sum=0;
            int cnt=0;
            while(r<nums.size()){
                  sum+=nums[r];
                  while(sum>goal)  {
                    sum-=nums[l];
                    l++;
                  }
                  cnt+=(r-l+1);   //the length
                  r++;
            }
            return cnt;
    
        }

        
        int numSubarraysWithSum(vector<int>& nums, int goal) {
             return f(nums,goal)-f(nums,goal-1);
        }
    };