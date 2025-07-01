#include <bits/stdc++.h>
using namespace std;


// Input: strs = ["flower","flow","flight"]
// Output: "fl"


//brute force__________________________________
//check for each word

//optimised__________
//sort the words and compare the first and last words.

class Solution {
    public:
        string longestCommonPrefix(vector<string>& str) {
            string ans="";
            sort(str.begin(),str.end());   //O(nlogn)
            int n=str.size();
            string first=str[0],last=str[n-1];
            
            for(int i=0; i<min(first.size(),last.size()); i++){
                if(first[i]!=last[i]) return ans;
                else ans+=first[i];
            }
            return ans;
    
        }
    };