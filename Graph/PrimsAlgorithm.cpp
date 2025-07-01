// to find mst
// we need priority queue, adjacency list, and a vector to store the parent of each node
// tc=O(ELogV)----> hr edge ko process krne ke liye, O(e) and  priority queue ka O(logv) kyuki usme nodes rhta h
//sc=O(v+e)


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;   //ultimate ans

        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

        pq.push({0, 0}); //{wt,node}

        while (!pq.empty())
        {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;

            pq.pop();
            if (vis[node] == 1)   //no operations since already added to  mst
                continue;

            sum += wt;
            vis[node] = 1; // note-->mark visited when added the weight in mst

            for (auto i : adj[node])
            {
                int u = i[0]; //  [{u,w},{u,w}] -->for adj[node]
                int w = i[1];
                if(vis[u]==0){
                    pq.push({w, u});
                }                
            }
        }

        return sum;
    }
};
