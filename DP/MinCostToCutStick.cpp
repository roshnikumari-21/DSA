// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs
// of all cuts. minimise the cost of cutss

// sort the cuts array.....to solve problem independently
// insert 0 at front and n at last in the cuts array
// take i=start ind,j=last ind


//tc=O(c^3)
//sc=O(c^2)-->dp table +O(c)-->recursion depth


#include <bits/stdc++.h>
using namespace std;

#define ll long long



class Solution
{
public:
    ll f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        ll mini = INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];


        for (int k = i; k <= j; k++)
        {
            ll cost = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }


    ll minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return f(1, c, cuts, dp);
    }
};