#include <bits/stdc++.h>
using namespace std;


//dijkstra not valid for negative weight cycle, nor on any negative weight


//using priority queue_____________________________________

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    //tc=O(V+E(logv))

    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //min pq
        pq.push({0, src});    //dist,node
        int v = adj.size();
        vector<int> dist(v, 1e9);
        dist[src] = 0;
        vector<int> parent(v);     
        for (int i = 0; i < v; i++)
            parent[i] = i;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            for (auto i : adj[node])
            {
                int no = i.first;
                int we = i.second;
                if (dis + we < dist[no])
                {
                    dist[no] = dis + we;
                    parent[no] = node;    //for path printing
                    pq.push({dis + we, no});
                }
            }
        }
        return dist;
    }
};




//A priority queue (min-heap) keeps track of the next best node to visit — the one with the smallest current distance.

// This makes sure you're always exploring the shortest possible path first, just like how a greedy algorithm works.




//using set __tc= O((V + E) * log V)_________________sc=O(v+e)_________________________
//set has a liberty to erase ...the not so better distance

//set is faster 

//adj list, sc=O(v+e)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest distance from source vertex S
    vector<int> dijstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st; // set to get min distance node
        vector<int> dist(V, 1e9); // initialize distances with large value

        dist[S] = 0; // Distance to source is 0
        st.insert({0, S}); // insert source with distance 0

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int node = it.second;
            int dis = it.first;

            for (auto nbr : adj[node]) {
                int adjNode = nbr[0];
                int edgeW = nbr[1];

                if (dis + edgeW < dist[adjNode]) {
                    // If a shorter path is found
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};