// Input: nums = [2,3,-2,4]
// Output: 6

//Given an integer array nums, find a subarray that has the largest product, and return the product.


//brute_________O(N^2)________________________
//tc=O(N)______________ sc=O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int pre = 1;
        int suf = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;
            pre = pre * nums[i];
            suf = suf * nums[n - i - 1];

            maxi = max(maxi, max(pre, suf));
        }

        return maxi;
    }
};