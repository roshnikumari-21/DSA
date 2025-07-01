
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Input: n = 1
// Output: ["()"]


//brute______________tc=O(2^n)________________________sc=O(2n)_________________________________

class Solution {
    public:
        vector<string> result;
    
        bool isValid(string str) {
            int count = 0;
            for (char ch : str) {
                if (ch == '(')
                    count++;
                else
                    count--;
                if (count < 0)
                    return false;
            }
            return count == 0;
        }
    
        void solve(string& curr, int n) {
            if (curr.length() == 2 * n) {
                if (isValid(curr)) {
                    result.push_back(curr);
                }
                return;
            }
    
            curr.push_back('(');
            solve(curr, n);
            curr.pop_back();
    
            curr.push_back(')');
            solve(curr, n);
            curr.pop_back(); // missing in original code, but should be here
        }
    };
    

//___________________________________________________________

//sc=O(2N)   tc=O(cn*2n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans; // global variable
    string s = "";
    
    void f(int n, int open, int close)
    {
        if (s.size() == n * 2)
        {            
            ans.push_back(s);
            return;
        }
        if (open < n)
        {
            s.push_back('(');
            f(n, open + 1, close);
            s.pop_back();
        }

        if (close < open)
        {
            s.push_back(')');
            f(n, open, close + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int open = 0, close = 0;
        f(n, open, close);
        return ans;
    }
};