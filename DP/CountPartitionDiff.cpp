// what if {0,0,1} then number of subsets will be 4 for finding sum=1
//(0,0,1)   (0,1)   (0,1 )  (1)

// count no. of zeroes
// ans=  ans*(pow(2,no of zeroes))

//Partitions With Given Difference such that  ---> s1-s2=d


#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int ind, vector<int> &arr2, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (ind >= arr2.size())
        return 0;

    if (dp[ind][k] != -1)
        return dp[ind][k];
        
    int take = 0;
    int ntake = solve(ind + 1, arr2, k, dp);
    if (arr2[ind] <= k)
        take = solve(ind + 1, arr2, k - arr2[ind], dp);
    return dp[ind][k] = (take + ntake) % mod;
}


int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = 0, cnt = 0;
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0)
            cnt++;
        else
            arr2.push_back(arr[i]);
    }

    sum = sum - d;
    if (sum % 2 == 1)
        return 0;   //early return
    if (sum < 0)
        return 0;     //early return
    int k = sum / 2;
    vector<vector<int>> dp(arr2.size() + 1, vector<int>(k + 1, -1));
    int powi = (1LL << cnt) % mod;

    return (1LL * (powi) % mod * solve(0, arr2, k, dp) % mod) % mod;
}
