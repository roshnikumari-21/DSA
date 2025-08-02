#include <bits/stdc++.h>
using namespace std;


//using kahn's algorithm
//topo sort only applicable to dag

//tc=O(v+e)
//sc=To store the adjacency list: O(V + E)


class Solution
{
public:
    bool f(vector<vector<int>> &adj)
    {
        int v = adj.size();
        queue<int> q;
        int ind[v] = {0};
        for (auto i : adj)
        {
            for (auto j : i)
            {
                ind[j]++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node])
            {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
            }
        }

        if (ans.size() < v)
            return true;         //cycle is present
        else
            return false;
    }
   
    bool isCyclic(int V, vector<vector<int>> adj)
    {
        return f(adj);
    }
};