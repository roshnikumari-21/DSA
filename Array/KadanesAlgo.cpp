#include <bits/stdc++.h>
using namespace std;


//Given an integer array nums, find the subarray with the largest sum, and return its sum.

//brute________________O(n^3)_____________________________________________________________
//using 3 loops

//better_________________O(n^2)________________________________________________________________
//using 2 loops

//optimal_____________________O(N)



class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int lmax = -1e9, gmax = -1e9;
        for (int i = 0; i < n; i++)
        {
            lmax = max(nums[i], lmax + nums[i]);
            gmax = max(gmax, lmax);
        }

        return gmax;
    }
};

//another variation of kadanes algo______________________
//if we carry negative number forward it will produce negtive sum...thats why

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n=nums.size();
            int maxi=INT_MIN;
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=nums[i];
                if(sum>maxi) maxi=sum;
                if(sum<0) sum=0;            
            }
    
            return maxi;
    
    
        }
    };



    //print any of those subarrays___________________________

    class Solution {
        public:
            int maxSubArray(vector<int>& nums) {
                int n = nums.size();
                int maxi = INT_MIN;
                int sum = 0;
                int ansstart = -1, ansend = -1, start = 0;
                for (int i = 0; i < n; i++) {
                    if (sum == 0)
                        start = i;
                    sum += nums[i];
                    if (sum > maxi) {
                        maxi = sum;
                        ansstart = start;
                        ansend = i;
                    }
                    if (sum < 0)
                        sum = 0;
                }
        
                for (int i = ansstart; i <= ansend; i++) {
                    cout << nums[i] << " ";
                }
        
                return maxi;
            }
        };