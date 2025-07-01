#include <bits/stdc++.h>
using namespace std;

//tc=O(N^3)

class Solution
{
public:
    int f(int n, int r)
    {
        int res = 1, m = 1, s = r;
        while (s--)     //O(n)
        {
            res *= n;
            res /= m;
            m++;
            n--;
        }
        return res;
    }
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> res;
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)    //O(N^2)
            {
                v.push_back(f(i, j));
            }
            res.push_back(v);
            v.clear();
        }
        return res;
    }
};


// optimised_____tc=O(N^2)_____________________________________________________

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);  // First element is always 1

    for (int col = 1; col < row; col++) {       //O(N)
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// Function to generate the entire Pascal's Triangle up to row N
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) {      //O(N)
        ans.push_back(generateRow(i));
    }
    return ans;
}