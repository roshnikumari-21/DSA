#include <bits/stdc++.h>
using namespace std;

// Return the number of ways you can arrive at your destination in the shortest amount of time.
//  Since the answer may be large, return it modulo 109 + 7.

// dijkstra's algorithm
// maked another array ways to store number of ways of reaching that node with smallesst path

#define ll long long

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<ll, ll>>> adj(n);
        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        vector<ll> dist(n, 1e12), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;            //note
        ll mod = (ll)1e9 + 7;

        while (!pq.empty())
        {
            auto it = pq.top();
            ll node = it.second;
            ll dis = it.first;
            pq.pop();
            for (auto i : adj[node])
            {
                ll wei = i.second;
                ll adjn = i.first;
                if (wei + dis < dist[adjn])
                {
                    dist[adjn] = wei + dis;
                    ways[adjn] = ways[node];
                    pq.push({wei + dis, adjn});
                }
                else if (wei + dis == dist[adjn])
                {
                    ways[adjn] = (ways[adjn] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};