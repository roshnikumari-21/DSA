#include <bits/stdc++.h>
using namespace std;


//   https://leetcode.com/problems/simplify-path/description/

//tc=O(n^2)______sc=O(n)

class Solution {
public:
    string simplifyPath(string arr) {
        stack<string> st;
        int n = arr.size();

        stringstream ss(arr);
        string temp;
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".")
                continue;
            else if (temp == "..") {
                if (!st.empty())
                    st.pop();
            }

            else
                st.push(temp);
        }

        string ans = "";

        while (!st.empty()) {
            string s = st.top();
            st.pop();
            ans = '/' + s + ans;
        }
        if (ans == "")
            ans = '/' + ans;
        return ans;
    }
};

//optimisation___________tc=O(n)  sc=O(N)
//using vector as a stack


class Solution {
public:
    string simplifyPath(string arr) {
        vector<string> st;
        int n = arr.size();

        stringstream ss(arr);
        string temp;
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".")
                continue;
            else if (temp == "..") {
                if (!st.empty())
                    st.pop_back();
            }

            else
                st.push_back(temp);
        }

        string ans = "/";

        for (int i = 0; i < st.size(); i++) {
            ans += st[i];
            if (i != st.size() - 1)
                ans += '/';
        }

        if (ans == "")
            ans = '/' + ans;
        return ans;
    }
};