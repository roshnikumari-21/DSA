// You are given a network of n nodes, labeled from 1 to n.
//  You are also given times, a list of travel times as directed edges
//   times[i] = (ui, vi, wi), where ui is the source node, vi is the target node,
//    and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it
//  takes for all the n nodes to receive the signal. If it is impossible for all the n nodes
//   to receive the signal, return -1.

//application of dijstra's algorithm


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto i : times)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n + 1, 1e9);
        dist[0] = 0;
        // queue<pair<int,int>>q;  //dist,node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[k] = 0;   //source node
        q.push({0, k});
        while (!q.empty())
        {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int node = it.second;
            for (auto i : adj[node])
            {
                int wei = i.second;
                int u = i.first;
                if (dis + wei < dist[u])
                {
                    dist[u] = dis + wei;
                    q.push({dis + wei, u});
                }
            }
        }

        int maxi = *max_element(dist.begin(), dist.end());
        if (maxi == 1e9)
            return -1;
        else
            return maxi;
    }
};