#include <bits/stdc++.h>
using namespace std;

// practise this....just implementation...

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]



class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();

        int top = 0, down = m - 1, left = 0, right = n - 1;
        int id = 0; // 0 1 2 3

        while (top <= down && left <= right)
        {
            if (id == 0)
            {
                for (int i = top; i <= right; i++)
                {
                    ans.push_back(mat[top][i]);
                }
                top++;
            }

            else if (id == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    ans.push_back(mat[i][right]);
                }
                right--;
            }

            else if (id == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(mat[down][i]);
                }
                down--;
            }

            else if (id == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }

            id = (id + 1) % 4;
        }

        return ans;
    }
};