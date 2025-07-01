#include <bits/stdc++.h>
using namespace std;

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.


//Staircase Search Algorithm_________________________________________
//tc=O(N+M)   sc=O(1)


class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int key)
    {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0)
        {
            if (mat[row][col] == key)
                return true;
            else if (mat[row][col] < key)
                row++;
            else
                col--;
        }
        return false;
    }
};


//binary searrch_____________tc=O(log(n*m))_____sc=O(1)_____________________

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0, high = (n * m) - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m;              //main partttt
            int col = mid % m;
            int midElement = matrix[row][col];
            
            if (midElement == target)
                return true;
            else if (midElement < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return false;
    }
};
