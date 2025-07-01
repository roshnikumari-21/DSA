// Input: s = "42"
//  Output: 42

//atoi stands for ASCII to Integer. It's a function in C/C++ used to convert
// a string (that represents a number) into its corresponding integer value.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int sign = 1;   //positive initialize
        long ans = 0;
        while (i < s.length() && s[i] == ' ')    //ignoring whitespaces
            i++;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;
        while (i < s.length())
        {
            if (s[i] >= '0' && s[i] <= '9')   //check for digit char
            {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX && sign == -1)
                    return INT_MIN;
                else if (ans > INT_MAX && sign == 1)
                    return INT_MAX;
                i++;
            }
            else
                return ans * sign;
        }
        return (ans * sign);
    }
};