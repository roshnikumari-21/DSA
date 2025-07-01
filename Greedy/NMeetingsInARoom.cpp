#include <bits/stdc++.h>
using namespace std;

// greedily, take meetings which end faster...thus sort it basis of ending time

class Solution
{
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;   //ascending order
    }


    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<pair<int, int>> vp;
        int n = start.size();
        int maxi = *max_element(end.begin(), end.end());
        for (int i = 0; i < n; i++)
        {
            vp.push_back({start[i], end[i]});
        }
        sort(vp.begin(), vp.end(), cmp);
        // vector<int>vis(maxi,0);
        int ans = 1;
        int et = vp[0].second;     //ending time
        for (int i = 1; i < n; i++)
        {
            if (vp[i].first <= et)
                continue;
            else
            {
                et = vp[i].second;
                ans++;
            }
        }
        return ans;
    }
};