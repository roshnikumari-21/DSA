// Given an unsorted array of integers nums, return the length of the longest consecutive
//  elements sequence.

// Input: nums = [100,4,200,1,3,2]
// Output: 4

//brute____________________tc=O(n^2)________________________


#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int n;
        bool ls(int val, vector<int>& nums) {      //linear search
            for (int i = 0; i < n; i++) {
                if (nums[i] == val)
                    return true;
            }
            return false;
        }
    
        int longestConsecutive(vector<int>& nums) {
            n = nums.size();    
            if (n == 0)
                return 0;

            int maxi = 0;
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                int val = nums[i] + 1;
                while (ls(val, nums) == true) {
                    cnt++;
                    val++;
                }
                maxi = max(maxi, cnt);
            }    
            return maxi;
        }
    };


//better______________________________________________________________________

class Solution {
    public:
        int n;
        int longestConsecutive(vector<int>& nums) {
            n = nums.size();
            if (n == 0)
                return 0;
            sort(nums.begin(), nums.end());    //O(nlogn)
    
            int curr = 1, maxi = 1, lastmin = INT_MIN;
    
            for (int i = 0; i < n; i++) {
                if (nums[i] == lastmin + 1) {
                    curr++;
                    lastmin++;
                } else if (nums[i] == lastmin) {
                    // do nothing
                } else {
                    maxi = max(maxi, curr);
                    curr = 1;
                    lastmin = nums[i];
                }
            }
    
            maxi = max(maxi, curr);
    
            return maxi;
        }
    };


  //optimal____________________tc=O(2n)_________________sc=O(n)______________________________________
  //check if the element is starting of the sequence  ...
  //agar us element ke pehle koi nii to, uwke aage loop lga kr check kr skti hooo

    class Solution {
        public:
            int longestConsecutive(vector<int>& nums) {        
                int n = nums.size();
                if (n == 0)    //edge cases
                    return 0;
        
                unordered_set<int> st;      //O(1)
        
                for (int i = 0; i < n; i++) {    //O(n)
                    st.insert(nums[i]);
                }
        
                int ans = 0;
        
                for (auto it : st) {           //O(N)
                    if (st.find(it - 1) == st.end()) {   //iske pehle koi nhi hai agar
                        int x = it;
                        int cnt = 1;
                        while (st.find(x + 1) != st.end()) {
                            cnt++;
                            x++;
                        }
        
                        ans = max(ans, cnt);
                    }
                }        
                return ans;
            }
        };