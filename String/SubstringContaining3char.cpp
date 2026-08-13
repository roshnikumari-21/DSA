// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these
//  characters a, b and c.

//aaabbaccac

#include <bits/stdc++.h>
using namespace std;

// tc=O(N^2) sc=O(1)

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        vector<int> v(3, 0);
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            v[0] = 0, v[1] = 0, v[2] = 0;
            for (int j = i; j < n; j++)
            {
                v[s[j] - 'a'] = 1;
                if (v[0] == 1 && v[1] == 1 && v[2] == 1)
                {
                    ans += (n - j);   //store ans for every substring after that
                    break;
                }
            }
        }
        return ans;
    }
};

// optimal_____________________________________________________________________
// tc=O(n) sc=O(1)

//every substring ends at a char...count from that char  towards leftward

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int a = -1, b = -1, c = -1;      //initially
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b')
                b = i;
            else if (s[i] == 'c')
                c = i;

            if (a != -1 && b != -1 && c != -1)
            {
                ans += min({a,b,c}) + 1;
            }
        }

        return ans;
    }
};
