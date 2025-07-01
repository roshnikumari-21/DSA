#include <bits/stdc++.h>
using namespace std;

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

//it works even for duplicates elements in array too
//tc=O(log(n))


//identify the sorted half


class Solution {
    public:
        bool search(vector<int>& nums, int tar) {
            int n = nums.size();
    
            int low = 0, high = n - 1, mid;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (nums[mid] == tar)
                    return true;
                if (nums[mid] == nums[low] && nums[mid] == nums[high]) {  //edge case
                    low++;
                    high--;
                    continue;
                }
    
                if (nums[low] <= nums[mid]) {               //if sorted array is in first half
                    if (tar >= nums[low] && tar <= nums[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {                  //if sorted array is in second half
                    if (tar >= nums[mid] && tar <= nums[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
    
            return false;
        }
    };

    //the other variation of this question is also same, just return the index there instead of true/false.
    //of target


    class Solution {
        public:
            int search(vector<int>& nums, int tar) {
        
                int n = nums.size();
                int st = 0, end = n - 1, mid, ind = -1;
                while (st <= end) {
                    mid = st + (end - st) / 2;
        
                    if (nums[mid] == tar)
                        return mid;
                    if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                        st++;
                        end--;
                        continue;
                    } else if (nums[st] <= nums[mid]) {
                        if (tar <= nums[mid] && tar >= nums[st]) {
                            end = mid - 1;
                        } else
                            st = mid + 1;
        
                    }
        
                    else {
                        if (tar <= nums[end] && tar >= nums[mid]) {
                            st = mid + 1;
                        } else
                            end = mid - 1;
                    }
                }
        
                return ind;
            }
        };