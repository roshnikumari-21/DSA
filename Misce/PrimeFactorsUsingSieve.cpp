//You are given a positive number N. Using the concept of Sieve, compute its prime factorisation.
//N = 12246
// Output: 
// 2 3 13 157

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void reals(vector<int> &v, int n)
    {
        for (int i = 0; i <= n; i++)
        {
            v[i] = i;
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (v[i] == i)    //starting point
            {
                for (int j = i * i; j <= n; j += i)
                {
                    if (v[j] == j)
                        v[j] = i;
                }
            }
        }
        return;
    }

   

    vector<int> findPrimeFactors(int N)
    {
        vector<int> ans;
        vector<int> v(N + 1, 0);
        reals(v, N);
        int val = N;
        while (val != 1)
        {
            val = v[N];
            if (val == 1)
                break;
            ans.push_back(val);
            N = N / val;
        }
        
        return ans;
    }
};