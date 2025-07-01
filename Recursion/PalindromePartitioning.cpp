// Given a string s, partition s such that every substring of the partition is a palindrome.
//  Return all possible palindrome partitioning of s.

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool ispali(string temp, int st, int end)    //recursive
    {
        if (end <= st)
            return true;

        if (temp[st] != temp[end])
            return false;
        return ispali(temp, st + 1, end - 1);
    }

    void f(int ind, string s, int n)
    {
        if (ind == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < n; i++)
        {
            if (ispali(s, ind, i))
            {
                temp.push_back(s.substr(ind, i - ind + 1));

                f(i + 1, s, n);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        f(0, s, n);
        return ans;
    }
};