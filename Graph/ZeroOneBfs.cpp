
//given a graph having 0 and 1 as edge weights , so we have to find shortest distance from source same
// as dijkstra.... hence use same bfs with deque
//push in front if w==0
//push in back if w==1
//that's it..



#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void zeroOneBFS(vector<vector<pair<int, int>>>& adj, int src, vector<int>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[src] = 0;

    deque<int> dq;
    dq.push_front(src);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto it : adj[node]) {
            int nbr=it.first;
            int wt=it.second;
            if (dist[node] + wt < dist[nbr]) {
                dist[nbr] = dist[node] + wt;
                if (wt == 1) dq.push_back(nbr);
                else dq.push_front(nbr);  // zero weight has higher priority
            }
        }
    }
}
