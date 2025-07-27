#include <bits/stdc++.h>
using namespace std;

// brute________________________
// add all non-zeroers number to a temp array, then put back in original array
// tc=O(2n)   sc=O(len of non-zero numbers)

// better__________________
// tc=O(N^2) for worst case

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                int j = i + 1;

                while (j < n && nums[j] == 0)
                    j++;
                if (j >= n)
                    break;

                swap(nums[i], nums[j]);
            }
        }
    }
};

// optimal_____________________
// tc=O(N)

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[pos++]);
            }
        }
    }
};
