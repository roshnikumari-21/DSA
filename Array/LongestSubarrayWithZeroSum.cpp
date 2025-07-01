#include <bits/stdc++.h>
using namespace std;

// tc=O(Nlogn)
// sc=O(N)

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        map<int, int> mp;
        int n = arr.size();
        int sum = 0;
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
                maxi = max(maxi, i + 1);
            else if (mp.find(sum) != mp.end())
            {
                maxi = max(i - mp[sum], maxi);
            }
            else
            {
                mp[sum] = i;
            }
        }
        if (maxi == INT_MIN)
            return 0;
        return maxi;
    }
};