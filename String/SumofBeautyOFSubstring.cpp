// brute
// The beauty of a string is the difference in frequencies
//  between the most frequent and least frequent characters.


//already done

#include <bits/stdc++.h>
using namespace std;

//tc=O(N^2)

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            map<int, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[s[j] - 'a']++;
                int mini = INT_MAX, maxi = INT_MIN;
                for (auto it : mp)
                {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};