#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void fdfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
            vis[node] = 1; // dfs fxn ke andar aate hi visited mark kr doo
    
            for (auto it : adj[node]) {
                if (!vis[it])
                    fdfs(it, adj, vis);
            }
        }
        int findCircleNum(vector<vector<int>>& mat) {
            int n = mat.size();
            int ans = 0;
    
            vector<vector<int>> adj(n);
            for (int i = 0; i < n; i++) {   //convert adjmat to adjList
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1)
                        adj[i].push_back(j);
                }
            }
    
            vector<int> vis(n, 0);
    
            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    ans++;
                    fdfs(i, adj, vis);
                }
            }
            return ans;
        }
    };