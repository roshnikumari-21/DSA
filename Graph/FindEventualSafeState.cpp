
// reverse all the edges
// get all the nodes with indegree 0
// terminal nodes have always indegree 0

//using bfs---->topo sort

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<vector<int>> adji(v);

        for (int i = 0; i < v; i++)
        {
            for (auto j : adj[i])
            {
                adji[j].push_back(i);     //reverse the edges
            }
        }

       

        queue<int> q;
        vector<int> ind(v, 0);
        vector<int> ans;
        for (auto i : adji)
        {
            for (auto j : i)
            {
                ind[j]++;
            }
        }

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
            for (auto i : adji[node])
            {
                ind[i]--;
                if (ind[i] == 0)
                    q.push(i);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};