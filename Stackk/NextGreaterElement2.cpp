//circular array 

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]    

// Input: nums = [1,2,1]
// Output: [2,-1,2]

//tc=O(N)


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {

            while (!st.empty() && nums[i % n] >= st.top())   //dhyan dena
                st.pop();
            if (i < n)
            {
                if (st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};