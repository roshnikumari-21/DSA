#include <bits/stdc++.h>
using namespace std;

// brute______________tc=O(N*M)__________sc=O(M)___________________________________________________________

class Solution
{
public:
    void Pse(vector<int> &pse, vector<int> &hei)
    {
        stack<int> st;
        int n = hei.size();
        pse.resize(n, -1);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && hei[st.top()] >= hei[i])
                st.pop();
            if (!st.empty())
                pse[i] = st.top();
            else
                pse[i] = -1;
            st.push(i);
        }

        return;
    }

    void Nse(vector<int> &nse, vector<int> &hei)
    {
        stack<int> st;
        int n = hei.size();
        nse.resize(n, n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && hei[st.top()] > hei[i])
                st.pop();
            if (!st.empty())
                nse[i] = st.top();
            else
                nse[i] = n;
            st.push(i);
        }
        return;
    }


    
    int largestRectangleArea(vector<int> &hei)
    {
        vector<int> pse, nse;
        Pse(pse, hei);
        Nse(nse, hei);
        int maxi = INT_MIN;
        int n = hei.size();

        for (int i = 0; i < n; i++)
        {

            int res = (nse[i] - pse[i] - 1) * hei[i];   //ye dhyan doo...
            maxi = max(maxi, res);
        }
        return maxi;
    }
};

// optimal_____________________________________________________________________________________________
//O(n)

//while kicking out from stack , compute the rect size , update maxi..
//we are actually putting the index in stack

class Solution
{
public:
    int largestRectangleArea(vector<int> &hei)
    {
        stack<int> st;
        int n = hei.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && hei[st.top()] > hei[i])   //we got a smaller element at right
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
};