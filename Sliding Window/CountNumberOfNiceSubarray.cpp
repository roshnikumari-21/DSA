#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k < 0)
            return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        while (r < n)
        {
            sum += nums[r];
            while (sum > k)
            {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }



    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)    //changed to binary type
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        return f(nums, k) - f(nums, k - 1);
    }
};