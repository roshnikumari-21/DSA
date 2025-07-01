#include <bits/stdc++.h>
using namespace std;


//tc=O(4^n * n)

//sc=O(N)


class Solution {
    public:
        string temp = "";
        vector<string> ans;
        map<char, string> mp;
        int n;
        
        void f(string& dig, int ind) {
            if (ind >= n) {
                ans.push_back(temp);
                return;
            }
            char ch = dig[ind];
            string s = mp[ch];
            for (int i = 0; i < s.size(); i++) {
                temp += s[i];
                f(dig, ind + 1);
                temp.pop_back();
            }
        }
    
        vector<string> letterCombinations(string dig) {
            n = dig.size();
            if (dig == "")
                return {};
    
            mp['2'] = "abc";
            mp['3'] = "def";
            mp['4'] = "ghi";
            mp['5'] = "jkl";
            mp['6'] = "mno";
            mp['7'] = "pqrs";
            mp['8'] = "tuv";
            mp['9'] = "wxyz";
    
            f(dig, 0);
            return ans;
        }
    };