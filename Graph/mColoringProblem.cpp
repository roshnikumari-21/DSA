// tc=O(N^m)
// sc=O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // check if adj nodes are not of same color
    bool check(int node, int col, int v, vector<pair<int, int>> &edges, vector<int> &color)
    {
        for (auto i : edges)
        {
            int u = i.first, v = i.second;
            if ((u == node && color[v] == col) || (v == node && color[u] == col))
                return false;
        }
        return true;
    }



    bool f(int node, int v, vector<pair<int, int>> &edges, int m, vector<int> &color)
    {
        if (node == v)
            return true;
        for (int i = 1; i <= m; i++)
        {
            int col = i;
            if (check(node, col, v, edges, color))
            {
                color[node] = i;
                if (f(node + 1, v, edges, m, color))
                    return true;
                color[node] = 0;    //backtrack
            }
        }
        return false;
    }



    bool graphColoring(int v, vector<pair<int, int>> &edges, int m) //v=total no. of vertices
    {
        int node = 0;
        vector<int> color(v, 0);           // to track color of adj nodes
        return f(node, v, edges, m, color);
    }
};
