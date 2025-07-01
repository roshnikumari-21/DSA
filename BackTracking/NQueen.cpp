// we will do it column wise
// we have to return all posssible solutions
// we need to check only in 3 dir i.e ...left...left diagonal upward....left diagonal downward

#include <bits/stdc++.h>
using namespace std;

// tc= O(N!)--->firs col->n choice then n-1 , then n-2....
// sc=O(N²)

class Solution
{
public:
    bool check(int col, int row, vector<string> &ches, int n)
    {
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0)
        { // upper diagonal
            if (ches[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        while (col >= 0)
        { // left cols
            if (ches[row][col] == 'Q')
                return false;
            col--;
        }

        row = duprow;
        col = dupcol;

        while (row < n && col >= 0)
        { // lower diagonal
            if (ches[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &ches, vector<vector<string>> &ans,
               int n)
    {
        if (col == n)
        { // base case
            ans.push_back(ches);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (check(col, row, ches, n))
            {
                ches[row][col] = 'Q';
                solve(col + 1, ches, ans, n);
                ches[row][col] = '.';   //backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s = string(n, '.');
        vector<string> ches(n);
        for (int i = 0; i < n; i++)
        {
            ches[i] = s;     //a board
        }

        solve(0, ches, ans, n);
        return ans;
    }
};

// more optimised way  by hashing_____________________________________________

// store 3 vectors left , updiagonal and downdiagonal...
//  for updiagonal--> row+col
//  for downdiagonal--> n-1 + col-row

class Solution
{
public:
    void solve(int col, vector<string> &ches, vector<vector<string>> &ans,
               int n, vector<int> &left, vector<int> &updg, vector<int> &dodg)
    {
        if (col == n)
        { // base case
            ans.push_back(ches);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (left[row] == 0 && updg[row + col] == 0 &&      //dekh lena......
                dodg[n - 1 + col - row] == 0)
            {
                ches[row][col] = 'Q';
                left[row] = 1;
                updg[row + col] = 1;
                dodg[n - 1 + col - row] = 1;
                solve(col + 1, ches, ans, n, left, updg, dodg);
                ches[row][col] = '.';
                left[row] = 0;
                updg[row + col] = 0;
                dodg[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s = string(n, '.');
        vector<string> ches(n);
        for (int i = 0; i < n; i++)
        {
            ches[i] = s;
        }

        vector<int> left(n, 0), updg(2 * n - 1, 0), dodg(2 * n - 1, 0);

        solve(0, ches, ans, n, left, updg, dodg);

        return ans;
    }
};