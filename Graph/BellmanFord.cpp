// to find the shortest path  //single source shortest path
// works on negative edgses,and negative cycles also, whereas dijkstra will fail there!!!

// helps detect negative cycles
// applicable for directed graph.....if given undirected convert it first to directed using double edge

// relaxation for (n-1) times
//tc=O(V+E)


//edges = [[0,1,5], [1,0,3], [1,2,-1], [2,0,1]], src = 2

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
   
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }


        bool flag = true;
        for (auto it : edges)   //check negative cycle
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                flag = false;
                break;
            }
        }

        
        if (flag == false)
        {            
            return {-1};
        }
        else
            return dist;
    }
};