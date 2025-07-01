//concept of front partition



// at max k length of partition is allowed--->then entire subarray changes to maximum...

//try every partition possible,...then take the best possible partions
//just recursion---->tc=exponential
//rec+memoization----->tc= O(n*k)__________sc=O(n)+O(n)____________

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int n;
        int f(int i, vector<int>& arr, int k, vector<int>& dp) {
    
            if (i >= n)
                return 0;
    
            if (dp[i] != -1)
                return dp[i];

                
            int maxi = 0;
            int curmax = -1;      // for max element in that range
            for (int j = i; j < min(n, i + k); j++) {
                curmax = max(curmax, arr[j]);
                int temp = curmax * (j - i + 1) + f(j + 1, arr, k, dp);
                maxi = max(maxi, temp);
            }
            return dp[i] = maxi;
        }
    
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            n = arr.size();
            vector<int> dp(n + 1, -1);
            return f(0, arr, k, dp);
        }
    };


//tabulation________________________________________________________________



class Solution {
    public:
        int n;
        
    
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            n = arr.size();
            vector<int> dp(n + 1, 0);
    
            for (int i = n - 1; i >= 0; i--) {
    
                int maxi = 0;
                int curmax = -1; // for max element in that range
                for (int j = i; j < min(n, i + k); j++) {
                    curmax = max(curmax, arr[j]);
                    int temp = curmax * (j - i + 1) + dp[j + 1];
                    maxi = max(maxi, temp);
                }
                dp[i] = maxi;
            }
    
            return dp[0];
        }
    };