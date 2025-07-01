#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(vector<int> &arr, int n, int k, int mid)
    {
        int nos = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + arr[i] > mid)
            {
                nos++;
                sum = 0;
            }
            sum += arr[i];
        }
        if (sum)
            nos++;
        if (nos > k)
            return false;
        else
            return true;
    }


    int splitArray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int start = maxi, end = sum, mid, ans;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (f(arr, n, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};