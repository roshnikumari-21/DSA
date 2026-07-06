// step1: do topo sort
//step 2:take out nodes from stack one by one, relax the edges

#include <bits/stdc++.h>
using namespace std;

//tc=O(v+e)

class Solution
{
public:
    void topo(int node, vector<vector<pair<int, int>>> &adj, stack<int> &st, int vis[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i.first])
                topo(i.first, adj, st, vis);
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
        }
        stack<int> st;
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                topo(i, adj, st, vis);
        }

        vector<int> dis(V, 1e9);
        dis[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto i : adj[node])
            {
                int r = i.first;       //r is the node
                int w = i.second;
                if (dis[node] + w < dis[r])
                    dis[r] = dis[node] + w;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (dis[i] == 1e9)
                dis[i] = -1;
        }

        return dis;
    }
};