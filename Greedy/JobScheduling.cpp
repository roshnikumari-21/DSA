// Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
// Output: [3, 100]

// Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
// Output: [2, 60]

#include <bits/stdc++.h>
using namespace std;

static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;    //descending order
}

class Solution
{
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &ddl,
                              vector<int> &pro)
    {
        int n = id.size();

        int maxddl = *max_element(ddl.begin(), ddl.end());

        vector<bool> day(maxddl, false);
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({pro[i], ddl[i]});
        }

        sort(vp.begin(), vp.end(), cmp);
        int ans = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int profit = vp[i].first;
            int dd = vp[i].second - 1;   //convert to 0 based indexing
            for (int j = dd; j >= 0; j--)
            {
                if (day[j] == false)
                {
                    day[j] = true;
                    cnt++;
                    ans += profit;
                    break;
                }
            }
        }

        return {cnt, ans};
    }
};
