#include <bits/stdc++.h>
using namespace std;

///tc=O(V+E)

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<int> bfs;
        queue<int> qu;
        vector<int> vis(v, 0);
        qu.push(0);    //qu me daalte time visited mark kr do
        vis[0] = 1;
        
        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            bfs.push_back(node);         //nikalte time,bfs vector me daaal do
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    qu.push(it);
                }
            }
        }
        return bfs;
    }
};