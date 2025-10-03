#include <bits/stdc++.h>
using namespace std;


//recursion method____________________________________

class Solution {
    public:

        vector<vector<int>> ans;
        vector<int> temp;
        int n;
        
        void f(vector<int>& nums, int ind) {
            if (ind == n) {
                ans.push_back(temp);    
                return;
            }
            temp.push_back(nums[ind]);
            f(nums, ind + 1);        //take    
            temp.pop_back();
            
            f(nums, ind + 1);         //not take
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            n = nums.size();
            vector<int> temp;
    
            f(nums, 0);
            return ans;
        }
    };

//____________________________________________________bit manip______


#include <iostream>
#include <vector>
using namespace std;

void powerSet(vector<int> &arr) {
    int n = arr.size();
    int totalSubsets = (1 << n);  // 2^n subsets

    for (int mask = 0; mask < totalSubsets; mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // Check if the i-th bit is set
                cout << arr[i] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    powerSet(arr);
    return 0;
}
