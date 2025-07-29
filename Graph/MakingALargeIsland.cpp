#include <bits/stdc++.h>
using namespace std;

// using dsu
// covert each row,col to a single number, 1,2,3...  so , that we can represent it using single node
// formula ===> (row*m + col)

// using set to store parents, to avoid conflicts...

class DisjointSet
{

public:
    vector<int> size, parent;
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
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int cell = n * n;
        DisjointSet ds(cell);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = i + dr[k];
                        int ncol = j + dc[k];
                        if (nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 1)
                        {
                            int node = (i * n) + j;
                            int nnode = (nrow * n) + ncol;
                            ds.unionBySize(node, nnode);
                        }
                    }
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                set<int> st;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++)
                {
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    if (nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 1)
                    {
                        
                        int nnode = (nrow * n) + ncol;
                        st.insert(ds.findPar(nnode));
                    }
                }
                int sum = 1;
                for (auto it : st)
                {
                    sum += ds.size[it];
                }
                maxi = max(maxi, sum);
            }
        }

        for (int i = 0; i < n * n; i++)   //safety check if all cells are one ...
        {
            maxi = max(maxi, ds.size[ds.findPar(i)]);
        }

        return maxi;
    }
};
