// tc= o(2^n)*n, 2^n for number of subsets and O(n) for copying

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

//this is most optimal solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int n)
    {
        if (ind == n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind + 1, nums, ans, temp, n);
        temp.pop_back();

        solve(ind + 1, nums, ans, temp, n);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(0, nums, ans, temp, n);
        return ans;
    }
};