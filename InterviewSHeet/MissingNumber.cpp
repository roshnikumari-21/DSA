#include <bits/stdc++.h>
using namespace std;

//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that
// is missing from the array.

//__________________________________________________________
//brute
//tc=O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        int val=(n*(n+1)/2);
        return val-sum;
    }
};


//__better____________________________________
//tc=O(N)   sc=O(1)


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        for(int i=0; i<n; i++){
            ans=(ans^i);
            ans=(ans^nums[i]);
        }
        return ans;
    }
};


//_optimal_______________________________________________________
//tc=O(log(n)+nlogn)


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int st=0,end=n-1,mid,ans=n;
        while(st<=end){                        //binary search
            mid=st+(end-st)/2;
            if(nums[mid]>mid){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;

        }

        return ans;
    }
};