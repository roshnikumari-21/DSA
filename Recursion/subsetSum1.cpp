#include <bits/stdc++.h>
using namespace std;

// You are given an array 'nums' of ‘n’ integers.
// Return all subset sums of 'nums' in a non-decreasing order.

// brute =  generate all subsets using bit manipulation  O(2^n * N)__________________

// optimal ___________________________________

int sum = 0;
int n;
vector<int> ans;

void solve(int ind, vector<int> &num)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }

    sum += num[ind];
    solve(ind + 1, num);
    sum -= num[ind];

    solve(ind + 1, num);
}

vector<int> subsetSum(vector<int> &num)
{
    n = num.size();
    solve(0, num);
    sort(ans.begin(), ans.end());
    return ans;
}
