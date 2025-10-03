// Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

//this solution only works if the number given are not -1....
//tc=O(n × m × (n + m))_________________________

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        for(int  i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    for(int k=0; k<n; k++){
                      if(mat[i][k]!=0)   mat[i][k]=-1;
                    }

                    for(int k=0; k<m; k++){
                      if(mat[k][j]!=0)   mat[k][j]=-1;
                    }
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==-1) mat[i][j]=0;
            }
        }

        
        
    }
};







// brute force--->tc=O(n × m × (n + m))_________________________



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> copy;
        copy = mat;         // O(n * m)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (copy[i][j] == 0)
                {
                    for (int k = 0; k < n; k++)
                        mat[k][j] = 0;
                    for (int k = 0; k < m; k++)
                        mat[i][k] = 0;
                }
            }
        }
    }
};

// bettter_________tc=O(n*m)______sc=O(N+M)_______________

class Solution
{
public:
    void setZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> rows(n, 1);
        vector<int> cols(m, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (rows[i] == 0 || cols[j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }
    }
};

// optimal__________________________________________
// trying to reduce sc by marking extra vectors inside the matrix
//corner-right guy will not be updated...keep this in mind......edge cases

class Solution
{
public:
    void setZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int col0 = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    mat[i][0] = 0;
                    if (j != 0)
                        mat[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for (int i = n - 1; i > 0; i--)  //not for the 0th row and col
        {
            for (int j = m - 1; j > 0; j--)
            {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)   //first row
        {
            if (mat[0][0] == 0)
                mat[0][i] = 0;
        }

        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
                mat[i][0] = 0;          //first col will be marked
        }
    }
};
