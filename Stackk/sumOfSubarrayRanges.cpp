// You are given an integer array nums. The range of a subarray of nums is the
// difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// brute-->O(n2)
// use two loops generate all subarrays. and find max-min of each and add it to final ans.

// optimal_____________________

// by using  sumofsubarrayMAX-sumofsubarrayMIN
// tc=O(N)    sc=O(N)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    int n;
    void Nse(vector<ll> &nse, vector<ll> &arr)
    {
        stack<ll> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
    }

    void Pse(vector<ll> &pse, vector<ll> &arr)
    {
        stack<ll> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }

    ll sumSubarrayMins(vector<ll> &arr)
    {
        vector<ll> nse(n), pse(n);
        Nse(nse, arr);
        Pse(pse, arr);

        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = (sum + (1LL * arr[i] * left * right));
        }

        return sum;
    }

    void Nge(vector<ll> &nge, vector<ll> &arr)
    {
        stack<ll> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            nge[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
    }

    void Pge(vector<ll> &pge, vector<ll> &arr)
    {
        stack<ll> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            pge[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }

    ll sumSubarrayMax(vector<ll> &arr)
    {

        vector<ll> nge(n), pge(n);
        Nge(nge, arr);
        Pge(pge, arr);

        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i - pge[i];
            int right = nge[i] - i;
            sum = (sum + (1LL * arr[i] * left * right));
        }

        return sum;
    }

    ll subArrayRanges(vector<int> &arr)
    {
        n = arr.size();
        vector<ll> v;
        for (auto i : arr)
        {
            v.push_back(i);
        }
        return (sumSubarrayMax(v) - sumSubarrayMins(v));
    }
};