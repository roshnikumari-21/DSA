#include <bits/stdc++.h>
using namespace std;


//brute will take O(n^2) time.

//z[i] is the length of the longest substring starting at index i that is also a prefix of s.

// to use z method....
// append the text and pattern by special character
//tc=O(n+m)   sc=O(n+m)

//it is related but different with kmp


//s= ABABAC
//kmp= 001230
//z=003010



vector<int> zAlgorithm(string text, string pattern)
{
    string s = pattern + "#" + text;
    int n = s.size();

    vector<int> z(n, 0);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n &&
               s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    vector<int> ans;

    // Find pattern occurrences
    for (int i = 0; i < n; i++)
    {
        if (z[i] == pattern.length())
        {
            // Convert position in combined string
            ans.push_back(i - pattern.length() - 1);
        }
    }

    return ans;
}