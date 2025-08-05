// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.

// no duplicates...

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// brute way---->to use same code as combinationSum and just slighttly to it, store in  a set to avoid duplicates
// but then tc=O(2^n * k * log(setsize))

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<vector<int>> ans;
    vector<vector<int>> res;
    vector<int> temp;
    int n;
    void f(int ind, vector<int> &v, int tar)
    {
        if (tar == 0)
        {
            ans.insert(temp);
            return;
        }

        if (ind == n)
        {
            return;
        }

        if (tar >= v[ind])
        {
            temp.push_back(v[ind]);
            f(ind + 1, v, tar - v[ind]);    //main part..
            temp.pop_back();
        }

        f(ind + 1, v, tar);
    }

    vector<vector<int>> combinationSum2(vector<int> &v, int tar)
    {

        sort(v.begin(), v.end());

        n = v.size();

        f(0, v, tar);

        for (auto it : ans)
        {
            res.push_back(it);
        }

        return res;
    }
};

// optimal way____________yeee_______________________________________________________

class Solution
{
public:
    void f(int ind, vector<vector<int>> &ans, vector<int> &v, int tar,
           vector<int> &temp, int n)
    {

        if (tar == 0)
        {

            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < n; i++)
        {
            if (i > ind && v[i] == v[i - 1])
                continue;   //to avoid duplicates
            if (v[i] > tar)
                break;

            temp.push_back(v[i]);
            f(i + 1, ans, v, tar - v[i], temp, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &v, int tar)
    {

        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n = v.size();

        vector<int> temp;

        f(0, ans, v, tar, temp, n);

        return ans;
    }
};