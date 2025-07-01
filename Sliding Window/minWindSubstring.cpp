// Given two strings s and t of lengths m and n respectively, return the minimum window substring
// of s such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

#include <bits/stdc++.h>
using namespace std;

// Brute  _________ O(N2)________________________________________

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        if (n > m)
            return ""; // early return

        map<char, int> mp;
        int mini = INT_MAX, ind = -1, cnt = 0;

        for (int i = 0; i < m; i++)
        {
            cnt = 0;

            for (int j = 0; j < n; j++)
            {
                mp[t[j]]++;
            }

            for (int j = i; j < m; j++)
            {
                if (mp[s[j]] > 0)
                {
                    cnt++;
                }
                mp[s[j]]--;
                if (cnt == n && j - i + 1 < mini)
                {
                    mini = j - i + 1;
                    ind = i;
                    break;
                }
            }
            mp.clear();
        }

        if (ind == -1)
            return "";

        return s.substr(ind, mini);
    }
};

// optimal________O(n+m)_______________________________________________

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        map<char, int> mp;
        int mini = INT_MAX, ind = -1, cnt = 0;

        for (int i = 0; i < n; i++)
            mp[t[i]]++;

        int l = 0, r = 0;
        while (r < m)
        {
            if (mp[s[r]] > 0)
                cnt++;
            mp[s[r]]--;
            while (cnt == n)
            {
                if (r - l + 1 < mini)
                {
                    mini = r - l + 1;
                    ind = l;
                }
                if (l < m)
                {
                    mp[s[l]]++;
                }
                if (mp[s[l]] > 0)   
                    cnt--;
                l++;
            }
            r++;
        }

        if (ind == -1)
            return "";

        return s.substr(ind, mini);
    }
};