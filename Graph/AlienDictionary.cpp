// find out the alien order
//tc=O(V+E)

//here, N= no of strings and k is no of alphabets

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);

        // Calculate indegrees
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        vector<int> indegree(K, 0);

        // Build the graph
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for (auto it : topo)
        {
            ans += char(it + 'a');
        }
        return ans;
    }
};


//when the order is not possible__________>when larger string is before shorter one
//or when there is a cyclic dependyncy