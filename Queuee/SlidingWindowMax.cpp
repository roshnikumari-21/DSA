// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

// tle approach______________________O(n*(n-k))__________

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++)
        {
            int maxi = INT_MIN;
            for (int j = i; j < (i + k); j++)
            {
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};

// optimal ____________________________________________________________
// tc=O(2n)            sc=O(k)+O(n-k) for storing answer

// use a deque, ...put index, monotonically decreasing in nature
//deque push pop tc=O(1)

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() <= i - k) // out of rangee
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) // put the greater el at front
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1) // within range from k-1 to n , push back the ans..
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};