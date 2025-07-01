#include <bits/stdc++.h>
using namespace std;

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1  //k = adjacent flowers required
// Output: 3

class Solution
{
public:
    int f(vector<int> &v, int mid, int n, int k, int m)
    {

        int cnt = 0, tot = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= mid)
                cnt++;
            else
            {
                tot += (cnt / k);
                cnt = 0;
            }
        }
        tot += (cnt / k);

        if (tot >= m)
            return true;
        else
            return false;
    }

    int minDays(vector<int> &v, int m, int k)
    {
        long long n = v.size();
        if (n < (m * 1LL * k))
            return -1;    //early return
            
        int maxi = *max_element(v.begin(), v.end());
        int mini = *min_element(v.begin(), v.end());
        int start = mini, end = maxi, mid, ans;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (f(v, mid, n, k, m))
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