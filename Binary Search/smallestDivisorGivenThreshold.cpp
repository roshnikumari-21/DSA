#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5



class Solution
{
public:
    int f(vector<int> &v, int mid, int n, int k)
    {

        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += (v[i] / mid);
            if (v[i] % mid)
                tot++;
        }

        if (tot <= k)
            return true;
        else
            return false;
    }

    int smallestDivisor(vector<int> &v, int k)
    {

        long long n = v.size();
        int maxi = *max_element(v.begin(), v.end());
        int start = 1, end = maxi, mid, ans;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (f(v, mid, n, k))
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