#include <bits/stdc++.h>
using namespace std;

// A peak element in a 2D grid is an element that is strictly greater
// r than all of its adjacent neighbors to the left, right, top, and bottom.

// brute---->run loops and check each element
// tc=O(n*m*4)

// optimised one--->binary search

// you have to only return 1 peak element

// first get the mid column--->find max element from that column
//tc=O(NLog(M))   sc=O(1)

class Solution
{
public:
    int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col)
    {
        int maxValue = -1;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > maxValue)
            {
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;   //find mid column
            int maxRowIndex = findMaxIndex(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;

            if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
            {
                return {maxRowIndex, mid};
            }
            else if (mat[maxRowIndex][mid] < left)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};