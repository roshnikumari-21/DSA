#include <bits/stdc++.h>
using namespace std;

//like binary search

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//dutch national flag algorithm

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n=nums.size();
            int low=0,mid=0,high=n-1;
            while(mid<=high){
                if(nums[mid]==0){
                    swap(nums[mid],nums[low]);
                    mid++; low++;
                }
                else if(nums[mid]==1){
                    mid++;
                }
                else{
                    swap(nums[mid],nums[high]);
                    high--;
                }
    
            }
        }
    };