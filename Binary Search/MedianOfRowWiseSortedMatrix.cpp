#include <bits/stdc++.h>
using namespace std;

// Given a row-wise sorted matrix where the number of rows and columns
// is always odd, find the median of the matrix.

// Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
// Output: 5

// brute force--->convert to 1d array, sort and get median
// tc=O(n*m)*log(n*m)

//optimal__________tc=O(nlogm) 

class Solution
{
public:
    int countSmallEqual(vector<vector<int>> &mat, int m, int n, int x)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        { 
            //index of ith row...=number of elements smaller than x
            cnt += (upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin()); 
            
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int low = INT_MAX, high = INT_MIN;

        // point low and high to right elements:
        for (int i = 0; i < m; i++)
        {
            low = min(low, mat[i][0]);       // minimum in first column
            high = max(high, mat[i][n - 1]); // maximum in last column
        }

        int req = (n * m) / 2;   
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(mat, m, n, mid);
            if (smallEqual <= req)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
