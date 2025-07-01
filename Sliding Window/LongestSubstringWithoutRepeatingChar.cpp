

#include <bits/stdc++.h>
using namespace std;

// Input: s = "bbbbb"
// Output: 1

// Input: s = "abcabcbb"
// Output: 3

//brute----->O(n^2)_____________generating all substrings and checking_______________

int maxLengthSubstring(const string& s) {  
    int n = s.length();  
   
    int maxLen = 0;  

    for (int i = 0; i < n; i++) {  
        vector<int> hash(256, 0);
        
        int len = 0;  
        
        for (int j = i; j < n; j++) {  
            // If the character has not been seen in the current substring  
            if (hash[s[j]] == 0) {  
                hash[s[j]]++;  
                len++;  
                maxLen = max(maxLen, len);  
            } else {  
                // Break if we encounter a duplicate character  
                break;  
            }  
        }  
    }  
    
    return maxLen;  
}  

//optimal__________tc=O(N)___________sc=O(1)________________

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
            int l=0,r=0,maxi=0;
            vector<int>hash(256,-1);        //O(1)
            while(r<n){
                if(hash[s[r]]!=-1){     //repeating char is found
                    if(hash[s[r]]>=l) l=hash[s[r]]+1;  //if inside the current window, move pointer l to one after the repeating one
                }
                maxi=max(maxi,r-l+1);
                hash[s[r]]=r;   //storing or updating the index
                r++;
            }
            return maxi;
        }
    };