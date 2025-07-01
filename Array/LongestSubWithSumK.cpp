// Given an array arr[] containing integers and an integer k, your task is to
//  find the length of the longest subarray where the sum of its elements is equal 
//  to the given value k. If there is no subarray with sum equal to k, return 0.


//brute sol--->two loops --->O(n^2)



//optimal____________________________
//tc=O(n) 
//sc=O(n)

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        int sum=0,ans=INT_MIN;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            
            if (sum == k) {
                ans = i + 1;  // subarray from index 0 to i
            }
            
            
            int x=sum-k;
            if(mp.find(x)!=mp.end()){
                ans=max(ans,i-mp[x]);
            }
          if(mp.find(sum)==mp.end())  mp[sum]=i;
            
        }
        if(ans==INT_MIN) ans=0;
        return ans;
    }
};