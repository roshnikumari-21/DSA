#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// brute _________________
// using 2 for loops__________________________________--


//better_____________tc=O(n)______sc=O(n)____________


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans(n);
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            int a, b;
            if (i == 0)
                a = 1;
            else
                a = pre[i - 1];

            if (i == n - 1)
                b = 1;
            else
                b = suf[i + 1];

            ans[i] = a * b;
        }
        return ans;
    }
};

//__tc=O(n)___________sc=O(1)___________________________________--

#define ll long long

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        ll cnt = 0;
        ll n = nums.size();
        vector<int> ans(n);
        ll mul = 1, mul2 = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                cnt++;
        }

        bool f = 1;
        if (cnt >= 2)
            f = 0;

        for (int i = 0; i < n; i++)
        {
            mul *= nums[i];
            if (nums[i] != 0)
                mul2 *= nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                ans[i] = mul / nums[i];
            else if (f == 1)
                ans[i] = mul2;
            else
                ans[i] = 0;     //ek se jyada 0roes hai
        }
        return ans;
    }
};