#include <bits/stdc++.h>
using namespace std;


//this algorithm is used on wide scale on a number of websites

//dijkstra is not possible here....
//bcoz we need to store everything in terms of stops..

//here we dont need a pq bcoz the increase at each level is constant i.e. +1

//tc=O(E)

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        vector<vector<pair<int, int>>> adj(n);
        for (auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});    //making adj list
        }

        queue<pair<int, pair<int, int>>> q;       //stop,(node,dis)
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if (stop > k)
                continue; //no need to go further

            for (auto i : adj[node])
            {
                int u = i.first;
                int wei = i.second;
                if (wei + dis < dist[u] && stop <= k)
                {
                    dist[u] = wei + dis;
                    q.push({stop + 1, {u, wei + dis}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];    //final destination
    }
};