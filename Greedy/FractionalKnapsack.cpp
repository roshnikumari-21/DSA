#include <bits/stdc++.h>
using namespace std;


// Input: val[] = [10, 20, 30],
// wt[] = [5, 10, 15],
// capacity = 100
// Output: 60

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        double m = (double)a.first / a.second;
        double n = (double)b.first / b.second;
        return (m >= n);
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int W)
    {
        int n = val.size();
        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++)
        {
            vp.push_back({val[i], wt[i]});
        }

        sort(vp.begin(), vp.end(), cmp);   //descending order
        double pro = 0;

        for (int i = 0; i < n; i++)
        {
            if (vp[i].second <= W)
            {
                pro += vp[i].first;
                W -= vp[i].second;
            }
            else
            {
                pro += ((double)vp[i].first / vp[i].second) * W;
                break;
            }
        }

        return pro;
    }
};