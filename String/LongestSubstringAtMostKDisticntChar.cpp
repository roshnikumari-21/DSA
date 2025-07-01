// k=2
// abbbbbbc
// output:7

// k=3
// abcddefg
// output:4

// brute force______tc=O(n^2)__________sc=O(256) at worst

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int maxi = 0;
    set<char> st;
    for (int i = 0; i < n; i++)
    {
        st.clear();
        for (int j = i; j < n; j++)
        {
            st.insert(str[j]);
            if (st.size() > k)
                break;
            maxi = max(maxi, j - i + 1);
        }
    }
    return maxi;
}

// optimised code___________________O(n)+O(log256)________O(256)___________

#include <bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int maxi = 0;
    unordered_map<char, int> mp;
    int l = 0, r = 0;
    while (r < n)
    {
        mp[str[r]]++;
        while (mp.size() > k)
        {
            mp[str[l]]--;
            if (mp[str[l]] == 0)
                mp.erase(str[l]);
            l++;
        }

        maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}
