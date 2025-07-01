#include <bits/stdc++.h>
using namespace std;


// each node is visited once: O(V)
// For each node, we explore all of its neighbors (edges): O(E)

//tc=O(v+e)
//sc=O(v)

class Solution
{
public:
    void fdfs(int node, vector<vector<int>> &adj, vector<int> &dfs, vector<int> &vis)
    {
        vis[node] = 1;                   //dfs fxn ke andar aate hi visited mark kr doo
        dfs.push_back(node);            //dfs vector me daal do
        for (auto it : adj[node])
        {
            if (!vis[it])
                fdfs(it, adj, dfs, vis);
        }
    }
   
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<int> dfs;    //to store answer
        vector<int> vis(v, 0);
        int start = 0;
        fdfs(start, adj, dfs, vis);
        return dfs;
    }
};