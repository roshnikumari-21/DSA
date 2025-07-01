#include <bits/stdc++.h>
using namespace std;

//find longest subarray with atmost k zeroes 


class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            int maxi=0;
            int cnt=0;
            int i=0,j=0;
    
            while(j<n){            //note the indexing
                if(nums[j]==0) cnt++;
                if(cnt>k) {
                    if(nums[i]==0) cnt--;
                    i++;
                }
                if(cnt<=k) maxi=max(maxi,j-i+1);
                j++;
            }
            return maxi;
           
    
        }
    };