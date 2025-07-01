// Given a DAG(direct acyclic graph), return the Topological Sorting of a given graph.
// indegree---> no. of incoming edges

// insert all node with indegree 0 in the queue
// now take them out , making their adj nodes indegree decreased by 1

//tc=O(v+e)

#include <bits/stdc++.h>
using namespace std;


vector<int> topologicalSort(vector<vector<int>> &gr, int edg, int n)
{
    
    vector<int> ind(n, 0); // indegree vector
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < edg; i++)
    {
        int u = gr[i][0];
        int v = gr[i][1];
        ind[v]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        ans.push_back(nod);                //queue se bahar nikalte time, ans me store kr lo
        for (int i = 0; i < edg; i++)
        {
            int u = gr[i][0];
            int v = gr[i][1];
            if (u == nod)
            {
                ind[v]--;
                if (ind[v] == 0)
                    q.push(v);
            }
        }
    }
    return ans;
}


//other way using dfs______________
//tc=O(v+e)
//sc=O(v)


class Solution {
private:
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);   //last me push in stack
    }

    

public:
    // Function to return list containing vertices in Topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        int vis[V] = {0};
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};




