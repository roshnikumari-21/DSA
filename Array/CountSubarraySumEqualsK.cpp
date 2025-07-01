
// Input: nums = [1,2,3], k = 3
// Output: 2

// Input: nums = [1,1,1], k = 2
// Output: 2




#include <bits/stdc++.h>
using namespace std;


//brute force___________tc=O(N^2)
//using two loops..


//better_____________use concept of presum-k____________in map

//tc=O(Nlogn)________ sc=O(n)--->to store sums in map

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
    
            int n=nums.size();
            map<int,int>mp;
            int sum=0,ans=0;
            mp[0]=1;             //always have 0 as a subarray...
            for(int i=0; i<n; i++){
                sum+=nums[i];
                int val=sum-k;
                if(mp.find(val)!=mp.end())  ans+=mp[val];
                mp[sum]++;
            }
            return ans;
        }
    };


