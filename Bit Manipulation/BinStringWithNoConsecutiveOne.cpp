// You have been given an integer 'N'. Your task is to generate and return all binary strings of length 'N' 
// such that there are no consecutive 1's in the string.

//tc=O(2^n)___________sc=O(n)______________________________________

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(int N, string s)
{
    if (s.size() == N)
    {
        ans.push_back(s);
        return;
    }

    solve(N, s + "0");

    if (s.size() == 0 || s.back() != '1')
        solve(N, s + "1");
}

vector<string> generateString(int N)
{
    solve(N, "");

    return ans;
}