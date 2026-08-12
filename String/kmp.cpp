// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0

// most naive approach
// tc=O(n*m)--->brute force

// lps---->longest prefix suffix

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string hay, string ne)
    {
        int n = hay.size();
        int m = ne.size();

        for (int i = 0; i <= (n - m); i++)
        {
            string temp = hay.substr(i, m);
            if (temp == ne)
                return i;
        }
        return -1;
    }
};

//______________________________________________________________________________________

// kmp algorithm
// MIK

// lps= longest prefix which is equal to suffix of equal length...

//eg: str: abababd   pat: ababd

class Solution
{
public:
    void findlps(int m, string ne, vector<int> &lps)
    { // O(N)
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while (i < m)
        {
            if (ne[i] == ne[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string hay, string ne)
    { // O(M)
        int n = hay.size();
        int m = ne.size();

        vector<int> lps(m);
        findlps(m, ne, lps);

        int i = 0, j = 0;
        while (i < n)
        { // kmp algo
            if (hay[i] == ne[j])
            { // char matches
                i++;
                j++;
            }
            if (j == m)
            {
                return i - j;
            } // found pattern
            else if (hay[i] != ne[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++; // kuch nhi kr skte
            }
        }

        return -1;
    }
};

// using z function_______________________

class Solution
{
public:
    vector<int> computeZ(string s)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    int strStr(string haystack, string needle)
    {
        string combined = needle + "$" + haystack;
        vector<int> z = computeZ(combined);
        int len = needle.length();

        for (int i = 0; i < z.size(); i++)
        {
            if (z[i] == len)
            {
                // Index in haystack = i - len - 1
                return i - len - 1;
            }
        }
        return -1;
    }
};
