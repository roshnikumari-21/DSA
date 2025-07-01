// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
//  and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

//  Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

// first apporach--->creating a third array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans(m + n);   //using extra space
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                ans[k] = nums1[i];
                i++;
            }
            else
            {
                ans[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m)
        {
            ans[k] = nums1[i++];
            k++;
        }
        while (j < n)
        {
            ans[k] = nums2[j++];
            k++;
        }

        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = ans[i];
        }
    }
};

// optimal____________tc=O(m+n)________sc=O(1)________________________________

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int i = m - 1;
        int j = n - 1;
        int k = n + m - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        return;
    }
};