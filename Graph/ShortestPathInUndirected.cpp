#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        int v = N;
        vector<vector<int>> adj(v);
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int, int>> q;       //(nod,dis)
        vector<int> dist(v, 1e9);
        dist[src] = 0;
        q.push({src, 0});
        while (!q.empty())
        {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            for (auto i : adj[node])
            {
                if (d + 1 < dist[i])
                {
                    dist[i] = d + 1;
                    q.push({i, dist[i]});
                }
            }
        }

        vector<int> ans;
        for (auto i : dist)
        {
            if (i != 1e9)
                ans.push_back(i);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};