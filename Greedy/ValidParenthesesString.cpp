#include <bits/stdc++.h>
using namespace std;

// brute--->using recursion
// tc=O(3^n)--->3 branches

// if optimised using dp--->tc=O(N^2) sc=O(n^2)

//using greedy--->O(N)
//here we are trying to maintain a range

class Solution
{
public:
    bool checkValidString(string s)
    {
        int mini = 0;
        int maxi = 0;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                mini++;

                maxi++;
            }

            else if (s[i] == ')')
            {
                mini--;

                maxi--;
            }

            else
            {
                mini--;

                maxi++;
            }
            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false;
        }

        if (mini != 0)     //note
            return false;
        else
            return true;
    }
};