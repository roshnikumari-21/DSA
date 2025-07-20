#include <bits/stdc++.h>
using namespace std;

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//transpose and then reverse each row..


//brute
//tc=O(n^2) sc=O(n^2)

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>ans(n,vector<int>(n));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[j][n-1-i]=mat[i][j];   //transpose+reverse

            }
        }

        mat=ans;
        return;
        
    }
};



//optimal
//tc=O(n^2)     sc=O(1)
class Solution
{
public:
    void rotate(vector<vector<int>> &mat)
    {
        int n = mat.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(mat[i][j], mat[j][i]);      //transpose
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};