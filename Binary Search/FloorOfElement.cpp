#include <bits/stdc++.h>
using namespace std;


//or lower bound of element x

class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x)
    {
        sort(v.begin(), v.end());
        int start = 0, end = n - 1, mid, ans = -1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (v[mid] <= x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};
