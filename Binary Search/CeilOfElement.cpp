#include <bits/stdc++.h>
using namespace std;
//upper bound


class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose ceil is to find
    int findCeil(vector<long long> &v, long long n, long long x)
    {
        sort(v.begin(), v.end());
        int start = 0, end = n - 1, mid, ans = -1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (v[mid] >= x)
            {
                ans = mid;
                end=mid-1;
            }
            else
                start = mid +1;
        }
        return ans;
    }
};
