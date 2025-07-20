#include <bits/stdc++.h>
using namespace std;



//brute is 3 loops, O(n^3), sort krke set me daalenge to remove duplicate triplets

//better ---> use 2 loops and a hashset

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set<int> hash;
            for (int j = i + 1; j < n; j++) {
                int sum = -(nums[i] + nums[j]);
                if (hash.find(sum) != hash.end()) {
                    vector<int> temp = {nums[i], nums[j], sum};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//optimal______________________________________________________
//tc= O(n log n) + O(n²) = O(n²)____________________________

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // Sort the array first
            sort(nums.begin(), nums.end());    //O(NlogN)
            int n = nums.size();
            vector<vector<int>> ans;
    
            // Edge case: If the array has less than 3 elements, return empty result
            if (n < 3) return ans;
            
            for (int i = 0;   i < n - 2;   i++) {
                // Skip duplicate values for the first element
                if (i!=0 && nums[i] == nums[i - 1]) continue;
                
                int j = i + 1, k = n - 1;
                
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];

                    if (sum == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        
                        // Skip duplicates for the second and third elements
                        j++;
                        k--;
                        while (j < n && nums[j] == nums[j - 1]) j++;
                        while (k>=0 && nums[k] == nums[k + 1]) k--;
                        
                        
                    } else if (sum > 0) {
                        k--;  // Decrease sum by moving `k` to the left
                    } else {
                        j++;  // Increase sum by moving `j` to the right
                    }
                }
            }
            
            return ans;
        }
    };