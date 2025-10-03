// Given two equally sized 1-D arrays A, B containing N integers each.

// A sum combination is made by adding one element from array A and another element of array B.

// Return the maximum C valid sum combinations from all the possible sum combinations.

// A = [3, 2]
//  B = [1, 4]
//  C = 2
//  output= [7, 6]


#include <bits/stdc++.h>
using namespace std;

//tc=O(c*log(c))           sc=O(c)

vector<int> solve(vector<int> &a, vector<int> &b, int c)
{
    sort(a.rbegin(), a.rend());   //sort in desc order
    sort(b.rbegin(), b.rend());

    priority_queue<pair<int, pair<int, int>>> pq;  //max-heap
    set<pair<int, int>> st;
    vector<int> ans;


    pq.push({a[0] + b[0], {0, 0}});  //start with largest possible sum
    st.insert({0, 0});
    while (c--)         //O(c)
    {

        auto it = pq.top();
        pq.pop();
        int fi = it.first;    // Current largest sum
        int x = it.second.first;        //index in a
        int y = it.second.second;        //index in b

        ans.push_back(fi);
        if (st.find({x, y + 1}) == st.end())
        {
            int sum2 = a[x] + b[y + 1];
            pq.push({sum2, {x, y + 1}});
            st.insert({x, y + 1});
        }

        if (st.find({x + 1, y}) == st.end())
        {
            int sum2 = a[x + 1] + b[y];
            pq.push({sum2, {x + 1, y}});
            st.insert({x + 1, y});
        }
    }

    return ans;
}