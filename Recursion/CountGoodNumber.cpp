#include <bits/stdc++.h>
using namespace std;


// A digit string is good if the digits (0-indexed) at even indices are
//  even and the digits at odd indices are prime (2, 3, 5, or 7).


//tc=O(log(n))    sc=O(1)

class Solution
{
public:
    long long bin(long long x, long long n, long long N)
    {
        long long res = 1;
        while (n)
        {
            if (n % 2)
            {
                res = (res * x) % N; // Multiply the result by x if n is odd
                n--;                 // Reduce n by 1 (to make it even)
            }
            else
            {
                x = (x * x) % N; // Square x to reduce the power
                n = n / 2;       // Divide the power by 2
            }
        }
        return res % N;
    }

    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long N = 1e9 + 7;
        long long ans = (bin(5, even, N) * bin(4, odd, N)) % N;
        return ans;
    }
};