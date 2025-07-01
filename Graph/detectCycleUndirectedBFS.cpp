#include <bits/stdc++.h>
using namespace std;

//tc=O(v+2e)______sc=O(v)_________________

class Graph
{

public:
    bool bfs(int nod, vector<int> adj[], vector<int> &vis)
    {
        vis[nod] = 1;      //first mark visited before entering in queue

        queue<pair<int, int>> qu;    //{nod,parent}
        qu.push({nod, -1});
        while (!qu.empty())
        {
            auto it = qu.front();
            qu.pop();
            int a = it.first;
            int par = it.second;

            for (auto it : adj[a])
            {
                if (vis[it] == 1 && it != par)
                {
                    return true;
                }
                else if (vis[it] == 0)
                {
                    vis[it] = 1;            //mark visited before entering queue
                    qu.push({it, a});
                }
            }
        }
        return false;
    }


    
    bool detectCycle(int V, vector<int> adj[])   //this is adjacency matrix
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (bfs(i, adj, vis) == true)   //cycle present hai
                    return true;
            }
        }
        return false;
    }
};