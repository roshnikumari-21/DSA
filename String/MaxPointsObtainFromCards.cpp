#include <bits/stdc++.h>
using namespace std;

//tc=O(k)
//sc=O(1)
class Solution {
    public:
        int maxScore(vector<int>& nums, int k) {
            int n = nums.size();
            int lsum = 0, rsum = 0, maxSum = 0;
    
            // Calculate sum of the first k elements from the left
            for (int i = 0; i < k; i++) {
                lsum += nums[i];
            }
    
            maxSum = lsum;
            int rIndex = n - 1;
    
            // Replace elements from the left with elements from the right
            for (int i = k - 1; i >= 0; i--) {
                lsum -= nums[i];      // Remove left element
                rsum += nums[rIndex]; // Add right element
                rIndex--;
                maxSum = max(maxSum, lsum + rsum);
            }
    
            return maxSum;
        }
    };