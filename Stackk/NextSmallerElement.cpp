#include <bits/stdc++.h>
using namespace std;

//tc=O(n)
//sc=O(n)


vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n, -1);     // Initialize all elements as -1
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        // Pop elements that are greater or equal to current
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nse[i] = st.top();
        }
        st.push(nums[i]);
    }

    return nse;
}
