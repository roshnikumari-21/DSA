#include <bits/stdc++.h>
using namespace std;

//codewithMIK__________GOOGLE

//brute--->do dfs or bfs from each node, and find ans (tle approach)

//optimised___________tc=O(V+E)
//kind of topo sort, bfs at last of queue whatever wil be remaining that will be our answer
//answer can be either 2 or 1 nodes only

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edg) {
        unordered_map<int, vector<int>> adj;
        vector<int> ind(n);
        for (auto it : edg) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ind[u]++;
            ind[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 1)
                q.push(i);
        }

        vector<int>ans;

        while (n > 2) {
            int len = q.size();
            n -= len;
            while (len--) {
                int nod = q.front();
                q.pop();
                for (auto it : adj[nod]) {
                    ind[it]--;
                    if (ind[it] == 1)
                        q.push(it);
                }
            }

        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
       if(ans.size()==0) return {0};
        return ans;
    }
};


