//pepcoding
//important formula for solving this....
//str=c1+ m + c2
//if c1==c2   count(str)= count(c1m)+count(mc2)+1
//if c1!=c2    count(str)=count(c1m)+count(mc2)-count(m)


//prefix --->(i,j-1)
//suffix---->(i+1,j)
//bich wala part--->(i+1,j-1)



#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countPalindromicSubsequences(string &s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Single character substrings
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;     //diag. elements 

    // Fill DP table for substrings of length 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {        //i is starting index
            int j = i + len - 1;    //j is the ending index
            if (s[i] == s[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
    }

    return dp[0][n - 1];
}
