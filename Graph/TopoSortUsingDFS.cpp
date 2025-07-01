#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int ind, vector<vector<int>> &adj, int vis[], stack<int> &st)
    {
        vis[ind] = 1;         //dfs ke andar aate hi visited mark kr do
        for (auto i : adj[ind])
        {
            if (!vis[i])
                dfs(i, adj, vis, st);
        }
        st.push(ind);     //sbse last me push kroo
    }


    
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        stack<int> st;
        int v = adj.size();
        int vis[v] = {0};
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
