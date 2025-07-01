// Input: nums = [3,2,1]
// Output: [1,2,3]

// Input: nums = [1,2,3]
// Output: [1,3,2]

// brute force--->generate all permutation, store them in sorted order, do a linear search and find the
// answer
// tc=O(N! * N)+ O(Nlogn)




// the better would be to use STL next_permutation()

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        
        next_permutation(nums.begin(), nums.end());
    }
};

// optimal________________tc=O(3N)_______sc=O(1)

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), ind = -1, l;

        for (int k = n - 2; k >= 0; k--) // find the index(breakpoint)
        {
            if (nums[k] < nums[k + 1])
            {
                ind = k;
                break; // index pointing to smaller number at breakpoint
            }
        }
        
        if (ind == -1)           // edge case
        {
            reverse(nums.begin(), nums.end());     
        }  
        else
        {
            for (l = n - 1; l > ind; l--)
            {
                if (nums[l] > nums[ind])
                {
                    swap(nums[ind], nums[l]);
                    break;
                }
            }

            reverse(nums.begin() + ind + 1, nums.end()); // reverse rest of array...//O(n)
        }
    }
};