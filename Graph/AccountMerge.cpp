// using disjoint set

//tc=disjointset---->O(1)

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
    vector<vector<string>> mergeDetails(vector<vector<string>> &details)
    {
        DisjointSet ds(details.size());
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < details.size(); i++)
        {
            for (int j = 1; j < details[i].size(); j++)
            {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[details.size()];       //array of vectors
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;                    //actual answer
        for (int i = 0; i < details.size(); i++)
        {
            if (mergedMail[i].size() == 0)
                continue;
                
            sort(mergedMail[i].begin(), mergedMail[i].end());   //mlog(M)
            vector<string> temp;
            temp.push_back(details[i][0]); // Take the name
            for (auto it : mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};