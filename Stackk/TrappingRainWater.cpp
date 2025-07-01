 // Given n non-negative integers representing an elevation map where the width of each bar is 1,
//  compute how much water it can trap after raining.

#include <bits/stdc++.h>
using namespace std;

// first approach____________tc=O(3n)___________sc=O(2n)_______________

class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> premax(n, 0);
        vector<int> sufmax(n, 0);
        premax[0] = arr[0];
        sufmax[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            premax[i] = max(premax[i - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            sufmax[i] = max(sufmax[i + 1], arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < premax[i] && arr[i] < sufmax[i])
            {
                ans += (min(premax[i], sufmax[i]) - arr[i]);
            }
        }

        return ans;
    }
};

// optimised________________________tc=O(n)________sc=O(1)_____________________________________
//i either need leftmax either rightmax, dont need both of them.....
//traversing the smaller ones first
//then u will always end up  l and r at largest buliding..

class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();
        int lmax = 0, rmax = 0, tot = 0;
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (arr[l] <= arr[r])   
            {
                if (lmax > arr[l])
                    tot += (lmax - arr[l]);
                else
                    lmax = arr[l];   //lmax is updated
                l++;
            }
            else
            {
                if (rmax > arr[r])
                    tot += (rmax - arr[r]);
                else
                    rmax = arr[r];       //rmax is updated
                r--;
            }
        }
        return tot;
    }
};