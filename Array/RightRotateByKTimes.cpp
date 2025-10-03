#include <bits/stdc++.h>
using namespace std;


//____sc=O(n)__________________________

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> v;
        v = nums;
        k = k % n;       //very imp
        for (int i = 0; i < n; i++)
        {
            int ind = (i + k) % n;
            v[ind] = nums[i];
        }
        nums = v;
    }
};

//__________sc=O(1)_________________________________________________

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};



//_____________________________________________________________