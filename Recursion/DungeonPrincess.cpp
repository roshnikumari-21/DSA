

//  https://www.interviewbit.com/problems/dungeon-princess/

//binary search appraoch---->tle______________________


class Solution {
public:
    int n, m;
    bool check(int mid, int i, int j, vector<vector<int>>& dun) {
        if (i >= n || j >= m)
            return false;
        mid += dun[i][j];
        if (mid <= 0)
            return false;
        if (i == n - 1 && j == m - 1)
            return true;
        return check(mid, i + 1, j, dun) || check(mid, i, j + 1, dun);
    }

    int calculateMinimumHP(vector<vector<int>>& dun) {
        n = dun.size();
        m = dun[0].size();

        int st = 1, end = 1e8, mid;
        int ans;
        while (st <= end) {
            
            mid = st + (end - st) / 2;
            if (check(mid, 0, 0, dun)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};


//dp__________________________________________
//tc=O(n*m)____________sc=O(n*M)________________

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &a, int n, int m, vector<vector<int>> &dp)
{
    if (i >= n || j >= m)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1 && j == m - 1)
    {
        return dp[i][j] = max(1, 1 - a[i][j]);
    }

    int health = min(solve(i, j + 1, a, n, m, dp), solve(i + 1, j, a, n, m, dp));
    return dp[i][j] = max(1, health - a[i][j]);
}

int calculateMinimumHP(vector<vector<int>> &a)
{

    int n = a.size();

    int m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    if (n == 0 || m == 0)
        return 0;
    return solve(0, 0, a, n, m, dp);
}
