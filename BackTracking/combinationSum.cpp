// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

#include <bits/stdc++.h>
using namespace std;


//tc = O(2^n)__________

class Solution {
    public:
        int n;
        vector<vector<int>> ans;
        vector<int> temp;
    
        void solve(int ind, vector<int>& candi, int tar) {
    
            if (tar == 0) {
                ans.push_back(temp);
                return;
            }
            if (ind == n) {
                return;
            }
    
            if (candi[ind] <= tar) {
                temp.push_back(candi[ind]);
                solve(ind, candi, tar - candi[ind]);
                temp.pop_back();
            }
    
            solve(ind + 1, candi, tar);
        }

        
        vector<vector<int>> combinationSum(vector<int>& candi, int tar) {
            n = candi.size();
            solve(0, candi, tar);
            return ans;
        }
    };