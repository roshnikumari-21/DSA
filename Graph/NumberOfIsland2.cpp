#include <bits/stdc++.h>
using namespace std;

// online queries----> query->answer


// n * m is for DSU initialization,
// q is the number of queries,
// α(n * m) is the nearly constant time per query due to efficient DSU operations.



class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
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
        if (size[pu] < size[pv])
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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(int r, int c, int n, int m)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

vector<int> numberOfIslandII(int n, int m, vector<vector<int>> &que, int q)
{
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> ans;

    for (auto &it : que)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;
        int mynod = row * m + col;

        for (int i = 0; i < 4; i++)
        {
            int nx = row + dx[i];
            int ny = col + dy[i];

            if (check(nx, ny, n, m) && vis[nx][ny] == 1)
            {
                int nnod = nx * m + ny;
                if (ds.findPar(nnod) != ds.findPar(mynod))
                {
                    ds.unionBySize(nnod, mynod);
                    cnt--;
                }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}

