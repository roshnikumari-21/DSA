//brute forces
//max element in bitonic array



#include <bits/stdc++.h>
using namespace std;

//brute______________________O(N)________________________________________

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n=nums.size();
    
            if( n>1 && nums[0]>nums[1]) return 0; 
            for(int i=1; i<n-1; i++){            
               if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
            }
            return n-1;
        }
    };


    //optimised___________________________________


    //check for first and last element in advance, if found peak just return
    //3 manuual check for edge cases
    //works even for multiple peaks


    int findPeakElement(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n-1] > arr[n-2]) return n-1;
    
        int low = 1, high = n-2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            } else if (arr[mid] > arr[mid-1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        return -1;
    }
    