// sort all the edges according to their weight
// if edges not in same component , join them

// use of disjoint set, for a bidirectional graph, it might store edges two times
// but does'nt matter, algo will work fine

// tc=O(ElogE)_________________sc=O(E+V)


//edges ki list chahiye


#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }


    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
            
        else if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
         }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};



class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    //{0-->{node1,w1},{node2,w2}} is type ka haiii... for V vertices
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) // v+e
        {
            for (auto it : adj[i])
            {
                int wei = it[1];
                int adjn = it[0];
                edges.push_back({wei, {i, adjn}});
            }
        }

        sort(edges.begin(), edges.end()); // Elog(E)

        int ans = 0;
        DisjointSet ds(V);

        for (auto i : edges)
        {
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;

            if (ds.findPar(u) != ds.findPar(v))
            {
                ans += wt;
                ds.unionBySize(u, v);
            }
        }
        return ans;
    }
};
