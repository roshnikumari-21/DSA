//components--->use of disjoint set
//ans= n-(no. of components)

//do a coordinate mapping

//do code after

class DisjointSet {
    vector<int> size, parent;

public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
        else if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxr = 0, maxc = 0;
        for (auto it : stones) {
            maxr = max(maxr, it[0]);
            maxc = max(maxc, it[1]);
        }

        DisjointSet ds(maxr + maxc + 1);
        unordered_map<int, int> stonenode;

        for (auto it : stones) {
            int noder = it[0];
            int nodec = it[1] + maxr + 1;
            ds.unionBySize(noder, nodec);
            stonenode[noder] = 1;
            stonenode[nodec] = 1;
        }

        int cnt = 0;

        for (auto it : stonenode) {
            if (ds.findPar(it.first) == it.first)
                cnt++;
        }

        return n - cnt;
    }
};