//Return true if you can reach the last index, or false otherwise .
//You are initially positioned at the array's first index, and each element
// in the array represents your maximum jump length at that position.

// Input: nums = [3,2,1,0,4]
// Output: false

// Input: nums = [2,3,1,1,4]
// Output: true


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();
            int maxi=0;
            for(int i=0; i<n; i++){
                if(i>maxi) return false;  //if i can't reach a particular index...
                maxi=max(maxi,i+nums[i]);
            }
            return true;
    
        }
    };