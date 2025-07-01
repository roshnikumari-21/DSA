// if a graph has odd length cycle it can never be bipartite
// 2 colors only such that no two adj nodes have same color

//here using 0 and 1 as two color


//O(v+e)

//using dfs_________________________________________________

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, int c, vector<vector<int>> &gr, vector<int> &clr)
    {
        clr[node] = c;
        for (auto i : gr[node])
        {
            if (clr[i] == -1)
            {
                if (dfs(i, 1 - c, gr, clr) == false)
                    return false;
            }
            else if (clr[i] == (c))
                return false;
        }
        return true;
    }

    
    bool isBipartite(vector<vector<int>> &gr)
    {
        int v = gr.size();
        vector<int> clr(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (clr[i] == -1)
            {
                if (dfs(i, 0, gr, clr) == false)
                    return false;
            }
        }
        return true;
    }
};


//using bfs_________________________________________________


class Solution {
    // colors a component
private:
    bool check(int start, int V, vector<int> adj[], int col[]) {
        queue<int> q;
        q.push(start);
        col[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                // if the adjacent node is not colored
                if (col[it] == -1) {
                    // give the opposite color of the current node
                    col[it] = !col[node];
                    q.push(it);
                }
                // if the adjacent node has the same color, not bipartite
                else if (col[it] == col[node]) {
                    return false;
                }
            }
        }
        return true;
    }



public:
    bool isBipartite(int V, vector<int> adj[]) {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (check(i, V, adj, color)==false)
                    return false;
            }
        }
        return true;
    }
};
