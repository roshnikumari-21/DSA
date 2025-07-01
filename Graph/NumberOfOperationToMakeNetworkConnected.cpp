

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
        else if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &con)
    {
        DisjointSet ds(n);
        int extra = 0;
        for (auto it : con)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findPar(u) == ds.findPar(v))
            {
                extra++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }


        int cnt = 0, ans;
        for (int i = 0; i < n; i++)
        {
            if (ds.findPar(i) == i)   
                cnt++;          //cnt will store total components
        }
        ans = cnt - 1;           //we should have this number of cabels to connect all
        if (ans <= extra)
            return ans;
        else
            return -1;
    }
};