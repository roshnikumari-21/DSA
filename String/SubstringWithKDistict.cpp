#include <bits/stdc++.h>
using namespace std;

//focus on this question

// Given a string s of lowercase alphabets,
// count all possible substrings (not necessarily distinct) that have exactly k distinct characters.


//tc=O(n*logK) sc=O(K)-->of map

class Solution
{
public:
    int count(string s, int k)
    {
        int n = s.size();
        int start = 0;
        int cnt = 0;
        map<char, int> mp;
        for (int end = 0; end < n; end++)
        {
            mp[s[end]]++;
            while (mp.size() > k)
            {
                mp[s[start]]--;
                if (mp[s[start]] == 0)
                    mp.erase(s[start]);
                start++;
            }
            cnt += (end - start + 1);  // add len 
        }
        return cnt;
    }

    int countSubstr(string &s, int k)
    {
        return count(s, k) - count(s, k - 1);
    }
};


//if given integer array....take map<int,int> and same approach