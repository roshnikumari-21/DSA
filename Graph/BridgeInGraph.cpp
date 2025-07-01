// print all bridges
// bridge---->split into two componenets

// track---->time of insertion-->time at which you reach a node
// lowestTimeOfInsertin---->not store parent's low, apart from parent


//tarjan's algorithm
//tc=O(V+2E)+O(3N)   //linear
//sc=O(V+2E)           //linear


#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int timer = 1;   //global
    int v;
    vector<vector<int>> ans;

    void dfs(int nod, int parent, vector<vector<int>> &adj, vector<int> &vis, vector<int> &tn, vector<int> &low)
    {
        vis[nod] = 1;
        tn[nod] = low[nod] = timer;
        timer++;
        for (auto it : adj[nod])
        {
            if (it == parent)
                continue;

                
            if (vis[it] == 0)
            {
                dfs(it, nod, adj, vis, tn, low);
                low[nod] = min(low[nod], low[it]);
                // can this it----nod be a bridge
                if (low[it] > tn[nod])
                    ans.push_back({nod, it});
            }
            else
            {
                low[nod] = min(low[nod], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &con)
    {

        v = n; // no. of nodes

        vector<vector<int>> adj(n);

        for (int i = 0; i < con.size(); i++)
        {
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }

        vector<int> vis(n, 0);
        vector<int> tn(n), low(n);

        dfs(0, -1, adj, vis, tn, low);
        return ans;
    }
};