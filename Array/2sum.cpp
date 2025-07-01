#include <bits/stdc++.h>
using namespace std;

//tc=O(nlogn)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int key)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int r = nums[i];
            if (mp.find(key - r) != mp.end())
                return {i, mp[key - r]};
            mp[r] = i;   //storing index
        }
        return {-1, -1};
    }
};