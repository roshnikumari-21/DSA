#include <bits/stdc++.h>
using namespace std;

//practise this....just implementation...


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]


class Solution {
    public:
        void f(int i, int j, int n, vector<vector<int>>& mat, vector<int>& ans, int tot) {
            if (ans.size() == tot) return;
    
            // Traverse from left to right on the top row
            for (int k = i; k <= j;  k++) {
                ans.push_back(mat[i][k]);
            }
            if (ans.size() == tot) return;
    
            // Traverse from top to bottom on the right column
            for (int k = i + 1; k <= n; k++) {
                ans.push_back(mat[k][j]);
            }
            if (ans.size() == tot) return;
    
            // Traverse from right to left on the bottom row
            for (int k = j - 1; k >= i; k--) {
                ans.push_back(mat[n][k]);
            }
            if (ans.size() == tot) return;
    
            // Traverse from bottom to top on the left column
            for (int k = n - 1; k > i; k--) {
                ans.push_back(mat[k][i]);
            }
            if (ans.size() == tot) return;
    
            f(i + 1, j - 1, n - 1, mat, ans, tot);  //recursive
        }
    
        vector<int> spiralOrder(vector<vector<int>>& mat) {
            vector<int> ans;
            if (mat.empty()) return ans;
    
            int n = mat.size();
            int m = mat[0].size();
            int tot = n * m;
            f(0, m - 1, n - 1,  mat, ans, tot); // Note the additional `0` parameter for the left boundary
            return ans;
        }
    };