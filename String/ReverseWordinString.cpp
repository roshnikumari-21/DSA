//using tokenizer.....stringstream

// Metric	Complexity
// Time	O(n)
// Space	O(n)

#include <bits/stdc++.h>
using namespace std;

//not good for interview----but i was asked about it...
class Solution {
    public:
        string reverseWords(string s) {
            stringstream ss(s);
            string temp;
            string result = "";
    
            while (ss >> temp) {  // Extract each word from the stringstream
                if (!result.empty()) {
                    result = temp + " " + result;  // Reverse word order
                } else {
                    result = temp;   //for the very first time
                }
            }
    
            return result;  // Return the final reversed string
        }
    };


    //main approach_____tc=O(N)________________sc=O(1)___________________________________________
//MIK


    class Solution {
        public:
            string reverseWords(string s) {
                int n = s.size();
                reverse(s.begin(), s.end());    //pura reverse
                
                int  i=0, l = 0, r = 0; // hmare heroes l at start of word, r reaches to end of word
        
                while (i < n) {
                    while (i < n && s[i] != ' ') {
                        s[r++] = s[i++];   //char put kr rhe
                    }
                    if (l < r) {
                        reverse(s.begin() + l, s.begin() + r);
                        s[r] = ' ';
                        r++;
                        l = r;
                    }
                    i++; // increasing always
                }
                return s.substr(0, r - 1);
            }
        };