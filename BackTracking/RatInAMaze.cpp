#include <bits/stdc++.h>
using namespace std;

// User function template for C++
// Time	O(4^(N^2)) (worst case)
// Space	O(N^2) (for vis) + recursion + ans (can also be exponential)


//if asked in lexicographically order , (d,l,r,u)..


class Solution
{
public:
    vector<string> ans;     //global variable
    string temp = "";
    void f(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &vis, int n)
    {
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(temp);
            return;
        }

        if (row < 0 || col < 0 || row >= n || col >= n || vis[row][col] == 1 || mat[row][col] == 0)
        {
            return;   //check 
        }

        vis[row][col] = 1;

        temp += 'D';
        f(mat, row + 1, col, vis, n);
        temp.pop_back();

        temp += 'R';
        f(mat, row, col + 1, vis, n);
        temp.pop_back();

        temp += 'U';
        f(mat, row - 1, col, vis, n);
        temp.pop_back();

        temp += 'L';
        f(mat, row, col - 1, vis, n);
        temp.pop_back();

        vis[row][col] = 0;
    }

    
    vector<string> findPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (mat[n - 1][n - 1] == 0 || mat[0][0] == 0)
            return {"-1"};       //early return

        vector<vector<int>> vis(n, vector<int>(n, 0));
        f(mat, 0, 0, vis, n);

        if (ans.empty())
            return {"-1"};
        return ans;
    }
};
