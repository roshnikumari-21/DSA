// Input: s = "egg", t = "add"
// Output: true

// Input: s = "foo", t = "bar"
// Output: false



//we wil be neeeding two map to check condditon

//tc=O(n)  sc=O(26)

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char, char> mp1;   //O(1)
            unordered_map<char, char> mp2;
    
            int m = s.length();
    
            for(int i = 0; i < m; i++) {
                char ch1 = s[i];
                char ch2 = t[i];
    
                if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 ||
                   mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1) {
                    return false;
                }
    
                mp1[ch1] = ch2;
                mp2[ch2] = ch1;
            }
    
            return true;
        }
    };
    