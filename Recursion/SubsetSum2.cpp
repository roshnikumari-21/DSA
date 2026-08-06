//brute___________tc=O(2^n * n)_______________sc=(2^n * k)+ O(n)_________
//basically not return duplicate subset

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
            ans.push_back(ds);
            for (int i = ind; i < nums.size(); i++) {
                if (i != ind && nums[i] == nums[i - 1]) continue;
    
                ds.push_back(nums[i]);
                findSubsets(i + 1, nums, ds, ans);
                ds.pop_back();
            }
        }
    
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> ds;
            sort(nums.begin(), nums.end());   //to get duplicates together
            findSubsets(0, nums, ds, ans);
            return ans;
        }
    };
    