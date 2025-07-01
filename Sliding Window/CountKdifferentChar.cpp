#include <bits/stdc++.h>
using namespace std;

// You are given a string 'str' of lowercase alphabets and an integer 'k' .
// Your task is to return the count all the possible substrings that have exactly 'k'
// distinct characters.

// a unique approach usesd

int helper(string str, int k)    //finding no of substrings with at most k distinct char
{
    int n = str.size();
    unordered_map<char, int> mp;    //use un_map for better efficiency

    int i = 0, cnt = 0;

    for (int j = 0; j < n; j++)
    {
        mp[str[j]]++;

        while (i < n && mp.size() > k)
        {
            mp[str[i]]--;
            if (mp[str[i]] == 0)
                mp.erase(str[i]);
            i++;
        }

        cnt += (j - i + 1);    //dhyan do...
    }

    return cnt;
}

int countSubStrings(string str, int k)
{
    return helper(str, k) - helper(str, k - 1);
}
