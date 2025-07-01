#include <bits/stdc++.h>
using namespace std;

// Sample Input 1:

// 4             //n
// 10 20 30 10   //hei

// 3
// 10 50 10
// Sample Output 1:
// 20
// 0

// memoization...tc=O(n)    sc=O(n)

int solve(int ind, int n, vector<int> &hei, vector<int> &dp)
{
    if (ind == n - 1)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];
    int one = INT_MAX, two = INT_MAX;
    if (ind + 1 < n)
        one = abs(hei[ind + 1] - hei[ind]) + solve(ind + 1, n, hei, dp);
    if (ind + 2 < n)
        two = abs(hei[ind + 2] - hei[ind]) + solve(ind + 2, n, hei, dp);
    return dp[ind] = min(one, two);
}

int frogJump(int n, vector<int> &hei)
{
    vector<int> dp(n + 1, -1);
    return solve(0, n, hei, dp);
}

// tabulation_________________________________________________________________

int frogJump(int n, vector<int> &hei)
{
    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    for (int ind = 1; ind < n; ind++)
    {
        int one = INT_MAX, two = INT_MAX;
        one = abs(hei[ind] - hei[ind - 1]) + dp[ind - 1];
        if (ind > 1)
            two = abs(hei[ind] - hei[ind - 2]) + dp[ind - 2];
        dp[ind] = min(one, two);
    }

    return dp[n - 1];
}

//space optimised  to O(1)___________________________

int frogJump(int n, vector<int> &hei) {
    int prev1 = 0;  // dp[i-1]
    int prev2 = 0;  // dp[i-2]

    for (int i = 1; i < n; i++) {
        int jumpOne = abs(hei[i] - hei[i - 1]) + prev1;
        int jumpTwo = INT_MAX;
        if (i > 1)
            jumpTwo = abs(hei[i] - hei[i - 2]) + prev2;

        int curr = min(jumpOne, jumpTwo);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
