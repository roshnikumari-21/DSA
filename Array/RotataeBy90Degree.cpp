#include <bits/stdc++.h>
using namespace std;

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//transpose and then reverse each row..


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