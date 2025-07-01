#include <bits/stdc++.h>
using namespace std;

// do this
//tc=O(N*M)+O(N*2M)
//sc=O(N*M)+O(2*M)

class Solution
{
public:
    int find(vector<int> &hei)
    {
        stack<int> st;
        int n = hei.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && hei[st.top()] > hei[i])
            {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = (st.empty() ? -1 : st.top());
                maxi = max(maxi, (nse - pse - 1) * hei[el]);
            }
            st.push(i);
        }
        
        while (!st.empty())
        {
            int el = st.top();
            st.pop();
            int nse = n;
            int pse = (st.empty() ? -1 : st.top());
            maxi = max(maxi, (nse - pse - 1) * hei[el]);
        }
        return maxi;
    }


    
    int maximalRectangle(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;
        vector<int> temp(m, 0);
        // vector<vector<int>>temp(n,vector<int>(m,0));

        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == '1')
                temp[i] = 1;
        }
        // vector<int>cur(m,0);
        maxi = find(temp);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '1')
                    temp[j]++;
                else
                    temp[j] = 0;
            }
            maxi = max(maxi, find(temp));
        }

        return maxi;
    }
};







