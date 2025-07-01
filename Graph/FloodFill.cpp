// can be solved using bfs or dfs

// color all in same color

// start dfs with starting row and col
// create copy of given matrix

//tc=O(4*N*M)--->due to 4 directions...
//sc=O(N*M)+ O(N*M)-->recursive stack space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:

 
    void dfs(int row, int col, vector<vector<int>> &ans, int newColor,
             vector<int> &delRow, vector<int> &delCol, int iniColor)
    {
        int n = ans.size();
        int m = ans[0].size();

        ans[row][col] = newColor;

        // Check boundaries and conditions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                ans[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            {

                dfs(nrow, ncol, ans, newColor, delRow, delCol, iniColor); // Recur for adjacent cells
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int iniColor = image[sr][sc];        // Initial color
        vector<vector<int>> ans = image;     // Copy the original image
        vector<int> delRow = {-1, 0, 1, 0}; // Direction vectors for row
        vector<int> delCol = {0, 1, 0, -1}; // Direction vectors for column

        if (iniColor != newColor)
        {

            dfs(sr, sc, ans, newColor, delRow, delCol, iniColor); // Start DFS
        }

        return ans; // Return the modified image
    }
};