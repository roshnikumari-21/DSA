#include <bits/stdc++.h>
using namespace std;

// You are given a stream of 'n' non-negative integers as the input, and you have to group
//  the stream of integers in the form of disjoint intervals.
//codestorywithMIK

// brute way______________

class DisjointIntervals
{
public:
    set<int> st;

    DisjointIntervals()
    {
    }

    void addInteger(int val)
    {
        st.insert(val);
    }

    vector<vector<int>> getDisjointIntervals()
    {
        vector<vector<int>> ans;
        int fir = *st.begin();
        ans.push_back({fir, fir});
        for (auto it : st)
        {
            if (it == ans.back()[1])
                continue;
            else if (it - ans.back()[1] == 1)
                ans.back()[1] = it;
            else
                ans.push_back({it, it});
        }
        return ans;
    }
};

// optimal way_____________tc=_O(log(n)+k)______________________________________________________________

#include <bits/stdc++.h>

class DisjointIntervals
{
public:
    map<int, int> mp;

    DisjointIntervals()
    {
        mp.clear();
    }

    void addInteger(int val)
    {

        int left = val, right = val;

        auto bada = mp.upper_bound(val);
        if (bada != mp.begin())
        {
            auto chota = bada;
            chota--;

            if (chota->second >= val)
                return;
            if (chota->second == val - 1)
                left = chota->first;
        }

        if (bada != mp.end() && bada->first == val + 1)
        {
            right = bada->second;
            mp.erase(bada->first);
        }

        mp[left] = right;
    }

    vector<vector<int>> getDisjointIntervals()
    {
        vector<vector<int>> ans;

        for (auto it : mp)
        {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};