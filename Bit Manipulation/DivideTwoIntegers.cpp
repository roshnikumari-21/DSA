// brute--->use addition operator ...count and then return ans

// Input: dividend = 10, divisor = 3
// Output: 3


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int sum = 0;
        int count = 0;

        while (sum + divisor <= dividend)
        {
            count = count + 1;
            sum += divisor;
        }

        return count;
    }
};

// optimal_______________________________________________

// every number can be written as powers of 2
// use loops for getting the highest power of 2 which you can remove
// handle the sign of number separeately to avoid overflows
//tc=O(log(n)*log(n))---->bcoz both loops taking O(log(n))


class Solution
{
public:
    int divide(int divi, int di)
    {
        if (divi == di)
            return 1;   //just a simple early return

        bool sign = true;
        if (divi >= 0 && di < 0)         //sign handling
            sign = false;
        if (divi < 0 && di > 0)
            sign = false;
        long long n = abs(divi);
        long long d = abs(di);   

        long long ans = 0;
        while (n >= d)
        {
            long long cnt = 0;
            while (n >= d * (1LL << (cnt + 1LL)))
            {
                cnt++;
            }
            ans += (1LL << cnt);
            n -= ((1LL << cnt) * d);
        }
        if (ans > INT_MAX && sign == true)
            return INT_MAX;
        if (ans > INT_MAX && sign == false)
            return INT_MIN;
        if (sign == true)
            return ans;
        else
            return (-1LL * ans);
    }
};