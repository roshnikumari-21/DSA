#include <bits/stdc++.h>
using namespace std;

// brute_______________

// make all permutations ...using xor check if next digit differes only by one bit or not
//  tc=n! *n

// optimised________________
// using backtracking
//tc= 2^n * n

bool solve(int A, vector<int> &vis, vector<int> &ans)
{
    if (ans.size() == (1 << A))
    {
        return true;
    }
    int cur = ans[ans.size() - 1];
    for (int i = 0; i < A; i++)
    {
        int next = (cur ^ (1 << i));
        if (vis[next] == 0)
        {
            ans.push_back(next);
            vis[next] = 1;
            if (solve(A, vis, ans) == true)
                return true;
            vis[next] = 0;
            ans.pop_back();
        }
    }

    return false;
}

vector<int> grayCode(int A)
{
    vector<int> ans;
    int len = (1 << A);
    vector<int> vis(len, 0);
    vis[0] = 1;
    ans.push_back(0);
    solve(A, vis, ans);
    return ans;
}
