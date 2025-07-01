#include <bits/stdc++.h>
using namespace std;

//brute____________tc=O(n!*n)____________________________
//sc=O(n)--->recursion stack space


class Solution {
private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);    //O(N)
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }


public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()] = {0};
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};


//another approach_____________same tc and sc=O(n!*N)___________________________

class Solution
{
public:
    void f(int i, vector<int> &nums, vector<vector<int>> &ans, int n)
    {
        if (i == n)
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < n; j++)
        {
            swap(nums[i], nums[j]);
            f(i + 1, nums, ans, n);
            swap(nums[i], nums[j]);
        }
    }


    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        f(0, nums, ans, n);
        return ans;
    }
};