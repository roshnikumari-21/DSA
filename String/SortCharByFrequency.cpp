#include <bits/stdc++.h>
using namespace std;

// Given a string s, sort it in decreasing order based on the frequency of the characters.
//  The frequency of a character is the number of times it appears in the string.

// Input: s = "Aabb"
// Output: "bbAa"

// Input: s = "tree"
// Output: "eert"

class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        map<char, int> mp;
        vector<string> v(n + 1, "");
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        for (auto &i : mp)
        {
            int m = i.second;
            char ch = i.first;
            v[m].append(m, ch);
        }
        string ans = "";
        for (int i = n; i >= 0; i--)  //traverse from last
        {
            if (v[i] != "")
            {
                ans.append(v[i]);
            }
        }
        return ans;
    }
};