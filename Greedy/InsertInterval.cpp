#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &in, vector<int> &newIn)
    {
        vector<vector<int>> ans;
        int n = in.size();
        int m = newIn.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({in[i][0], in[i][1]});
        }
        vp.push_back({newIn[0], newIn[1]});

        sort(vp.begin(), vp.end());

        int nn = vp.size();

        for (int i = 0; i < nn; i++)
        {
            if (ans.size() == 0 || vp[i].first > ans.back()[1])   //no overlap
            {

                ans.push_back({vp[i].first, vp[i].second});
            }

            else
            {
                ans.back()[1] = max(ans.back()[1], vp[i].second); // overlap
            }
        }
        return ans;
    }
};