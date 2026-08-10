#include <bits/stdc++.h>
using namespace std;


// Input: s = "rat", t = "car"
// Output: false

 
// Input: s = "anagram", t = "nagaram"
// Output: true


//tc=O(nlogn)
class Solution {
    public:
        bool isAnagram(string s, string t) {
            int n=s.size();
            int m=t.size();
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s==t) return true;
            else return false;
    
        }
    };

