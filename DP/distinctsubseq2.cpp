
 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.length();

        vector<long long> dp(n + 1);
        dp[0] = 1;

        unordered_map<char, int> last;

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;

            char ch = s[i - 1];

            if (last.count(ch)) {
                int j = last[ch];
                dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;
            }

            last[ch] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};