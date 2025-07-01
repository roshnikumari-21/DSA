#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void Nse(vector<int> &nse, vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        nse.resize(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
    }

    void Pse(vector<int> &pse, vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        pse.resize(n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int N = 1e9 + 7;
        vector<int> nse, pse;
        Nse(nse, arr);
        Pse(pse, arr);
        int n = arr.size();
        long long sum = 0;

        for (int i = 0; i < n; i++)   //rememmber what u have done here
        {
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = (sum + (1LL * arr[i] * left * right) % N) % N;
        }

        return (int)sum;
    }
};