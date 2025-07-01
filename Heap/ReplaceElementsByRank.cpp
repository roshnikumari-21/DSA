// brute___________________________________________________________

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int n)
    {
        vector<int> brr = arr;
        sort(brr.begin(), brr.end());
        map<int, int> mp;
        int j = 1;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(brr[i]) == mp.end())
            {
                mp[brr[i]] = j;
                j++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};