#include <bits/stdc++.h>
using namespace std;

// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.

//  tc=O(V + E)

// void dfs(Node *node, Node *cnod, unordered_map<Node *, Node *> &mp)
// {
//     for (auto it : node->neighbors)
//     {
//         if (mp.find(it) == mp.end())
//         {
//             Node *ni = new Node(it->val);
//             mp[it] = ni;
//             cnod->neighbors.push_back(ni);
//             dfs(it, ni, mp);
//         }
//         else
//         {
//             cnod->neighbors.push_back(mp[it]);
//         }
//     }
// }

// class Solution
// {
// public:
//     Node *cloneGraph(Node *node)
//     {
//         if (node == NULL)
//             return NULL;
//         unordered_map<Node *, Node *> mp;
//         Node *cnod = new Node(node->val);
//         mp[node] = cnod;

//         dfs(node, cnod, mp);
//         return cnod;
//     }
// };