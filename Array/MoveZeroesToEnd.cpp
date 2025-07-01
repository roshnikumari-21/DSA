#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n=nums.size();
    
            for(int i=0; i<n; i++){
                if(nums[i]==0){
                    int j=i+1;
                    
                    while( j<n && nums[j]==0) j++;
                    if(j>=n) break;
                    
                    swap(nums[i],nums[j]);
                }
            }
        }
    };