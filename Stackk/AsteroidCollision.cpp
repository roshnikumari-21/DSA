#include <bits/stdc++.h>
using namespace std;

//tc=O(N)   sc=O(N)

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &v)
    {
        stack<int> st;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 0)    //push all positive ones
                st.push(v[i]);
            else
            {
                while (!st.empty() && abs(v[i]) > st.top() && st.top() > 0)  //positive wala chota h...
                    st.pop();
                    

                    //ab check kro negative wale ko push krna h ya nhi..
                if (!st.empty() && st.top() == abs(v[i]))  //equal h to dono gya....
                    st.pop();
                else if (st.empty() || st.top() < 0)       //negative elements mil gye
                    st.push(v[i]);   //agar stack empty hua to pehli baar negative element insert krenge
            }
        }

        
        vector<int> ans;
        while (!st.empty())   //stack se nikal kr vector me push kr do 
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};