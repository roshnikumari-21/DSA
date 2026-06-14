#include <bits/stdc++.h>
using namespace std;

// Return the least weight capacity of the ship that will result in all the packages
//  on the conveyor belt being shipped within d days.



class Solution
{
public:
    int f(vector<int> &v, int mid, int days, int n)
    {
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + v[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            if (v[i] > mid)
                return false;
            sum += v[i];
        }
        if (sum)
            cnt++;
        if (cnt > days)
            return false;
        else
            return true;
    }


    int shipWithinDays(vector<int> &v, int days)
    {
        int n = v.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
        }
        int start = 0, end = sum, mid, ans;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (f(v, mid, days, n))
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