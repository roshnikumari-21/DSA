// to find strongly connected componennts (scc)
//  A Strongly Connected Component (SCC) in a directed graph is a maximal subgraph
//   where every vertex is reachable from every other vertex in that subgraph.

// sort all the edges according to finshing time
// reverse the entire graph..reverse edges...

// so that the dfs happens only in each particular scc ...thus we can keep the count of it
// do the dfs

//tc=3*O(v+e)  for all the 3 steps



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int nod, vector<int> adj[], vector<int> &vis, stack<int> &st) {
        vis[nod] = 1; // Mark visited
        for (auto it : adj[nod]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(nod); // Push current node to stack after exploring all neighbors
    }

    void dfs2(int nod, vector<int> adjt[], vector<int> &vis) {
        vis[nod] = 1; // Mark visited
        for (auto it : adjt[nod]) {
            if (!vis[it]) {
                dfs2(it, adjt, vis);
            }
        }
    }

    int kosaraju(int v, vector<int> adj[]) {
        vector<int> vis(v, 0);
        stack<int> st;

        // 1. Order vertices by finish time
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // 2. Transpose the graph / reverse edges
        vector<int> adjt[v];
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                adjt[it].push_back(i);
            }
        }

        // 3. DFS on transposed graph in the order of decreasing finish time
        for (int i = 0; i < v; i++)
            vis[i] = 0; // Reset visited array

        int scc = 0; // Count of strongly connected components
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                scc++;
                dfs2(node, adjt, vis);
            }
        }

        return scc; // Final number of SCCs
    }
};