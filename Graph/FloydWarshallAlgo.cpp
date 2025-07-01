// multi-source shortest path algorithm
// helps detecting negative cycles in the graph
// Time complexity: O(V^3)

// go via every node/vertex
// something like dp coz we are pre-computing
// this algo is not much intuitive but a brute force, using 3 loops

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortestDistance(vector<vector<int>> &mat)
    {
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == -1)
                    mat[i][j] = 1e9;   //infinity....bs abhi ke liye..
            }   
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1e9)
                    mat[i][j] = -1;
            }
        }

        return;
    }
};
