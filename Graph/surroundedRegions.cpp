// You are given an m x n matrix board containing letters 'X' and 'O', capture regions
//  that are surrounded:

// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. 
// You do not need to return anything.

 #include <bits/stdc++.h>
 using namespace std;
 

 class Solution {
    public:
        int n, m;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
    
        void dfs(int row, int col, vector<vector<char>>& mat,
                 vector<vector<int>>& vis) {
            vis[row][col] = 1;
           
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
    
                if (nrow < n && nrow >= 0 && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O') {
                    dfs(nrow, ncol, mat, vis);
                }
            }
        }
        void solve(vector<vector<char>>& mat) {
            n = mat.size();
            m = mat[0].size();
    
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            //first row pr dfs
            for (int i = 0; i < m; i++) {  
                if (mat[0][i] == 'O' && vis[0][i] == 0) {
                    dfs(0, i, mat, vis);
                }
            }
    
            //last row pr dfs
            for (int i = 0; i < m; i++) {
                if (mat[n - 1][i] == 'O' && vis[n - 1][i] == 0) {
                    dfs(n - 1, i, mat, vis);
                }
            }
    
            for (int i = 0; i < n; i++) {
                if (mat[i][0] == 'O' && vis[i][0] == 0) {
                    dfs(i, 0, mat, vis);
                }
            }
    
            for (int i = 0; i < n; i++) {
                if (mat[i][m - 1] == 'O' && vis[i][m - 1] == 0) {
                    dfs(i, m - 1, mat, vis);
                }
            }
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (vis[i][j] == 1)
                        continue;
                    else
                        mat[i][j] = 'X';
                }
            }
    
            return;
        }
    };