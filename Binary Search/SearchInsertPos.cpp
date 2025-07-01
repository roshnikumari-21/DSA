#include <bits/stdc++.h>
using namespace std;

//Given a sorted array of distinct integers and a target value, 
//return the index if the target is found. If not, return the index where
// it would be if it were inserted in order.

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int n=nums.size();
            int start=0,end=n-1,mid,ind=n;
            while(start<=end){
                mid=start+(end-start)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) {ind=mid; end=mid-1;}
                else start=mid+1;
            }
            return ind;
        }
    };