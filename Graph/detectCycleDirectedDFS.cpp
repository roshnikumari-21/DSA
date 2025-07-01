#include <bits/stdc++.h>
using namespace std;

// on the same path node has to be visited again -->condition of cycle
// if both visited and path visited --->yes cycle

//  tc=O(v+e)

class Solution
{
public:
    bool dfs(int nod, int vis[], int pathvis[], vector<int> adj[])
    {
        vis[nod] = 1;
        pathvis[nod] = 1;

        for (auto it : adj[nod])
        {
            if (vis[it] == 0)
            {
                if( dfs(it, vis, pathvis, adj)) return true;  //cycle found
            }
            else if (pathvis[it] == 1)
                return true;
        }

        pathvis[nod] = 0;    //backtrack
        return false;   //cycle nhi hai
    }


    
    bool isCyclic(int V, vector<int> adj[])  // adj list
    { 
        int vis[V] = {0};
        int pathvis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, vis, pathvis, adj) == true)  //cycle present hai
                    return true;
            }
        }
        return false;
    }
};
