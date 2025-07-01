// to find prime number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sieve(vector<int> &v, int n)
    {
        v[0] = 0;
        v[1] = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (v[i] == 1)    //we got a prime
            {
                for (int j = i * i; j <= n; j += i)
                {
                    v[j] = 0;   //mark all multiples as not prime
                }
            }
        }
    }
    int countPrimes(int n)
    {
        // int N=1e6*5+1;
        vector<int> v(n + 4, 1);
        sieve(v, n);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += v[i];
        }
        return ans;
    }
};