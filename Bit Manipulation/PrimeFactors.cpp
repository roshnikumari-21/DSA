// Given a number N. Find its unique prime factors in increasing order.

// Input: N = 100
// Output: 2 5

//tc=O(root(n)) 
//sc=O(log(n))

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(int n, map<int, int> &mp)
    {
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n /= i;
            }
        }
        if (n != 1)
            mp[n]++;
        return;
    }

    vector<int> AllPrimeFactors(int N)
    {
        vector<int> ans;
        map<int, int> mp;
        f(N, mp);
        for (auto i : mp)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};