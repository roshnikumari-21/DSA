// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]

//brute_______________tc=O(2N)________sc=O(N)

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& arr) {
            int n=arr.size();
            vector<int>a,b;
            
            for(int i=0; i<n; i++){
                if(arr[i]>0)  a.push_back(arr[i]);
                else b.push_back(arr[i]);
            }
            int i=0,j=0;
            for(int k=0; k<n; k++){
                 if(k%2==0 ){ arr[k]=a[i]; i++;}
                 else {arr[k]=b[j]; j++;}
                 
            }
            return arr;
        }
    };

    //optimal__________________
    //using two indexes
    //tc=O(N)  and     sc=O(N)

    class Solution {
        public:
            vector<int> rearrangeArray(vector<int>& nums) {
                int n = nums.size();
                vector<int> ans(n, 0);    //another array
                int posIndex = 0, negIndex = 1;
        
                for (int i = 0; i < n; i++) {
                    if (nums[i] < 0) {
                        ans[negIndex] = nums[i];
                        negIndex += 2;
                    } else {
                        ans[posIndex] = nums[i];
                        posIndex += 2;
                    }
                }
        
                return ans;
            }
        };

        
        //if number of positives != number of negative elementes
        //use brute force solution again

