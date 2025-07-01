// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0

//most naive approach
//tc=O(n*m)--->brute force

//lps---->longest prefix suffix

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int strStr(string hay, string ne) {     
            int n=hay.size();
            int m=ne.size();
    
            for(int i=0; i<=(n-m); i++){
                string temp=hay.substr(i,m);
                if(temp==ne) return i;    
            }
            return -1;   
        }
    };
    
//______________________________________________________________________________________

    //kmp algorithm
    //MIK

    //lps= longest prefix which is equal to suffix of equal length...


    class Solution {
        public:
            void findlps(int m, string ne, vector<int>& lps) {    //O(N)
                lps[0] = 0;
                int len = 0;
                int i = 1;
                while (i < m) {
                    if (ne[i] == ne[len]) {
                        len++;
                        lps[i] = len;
                        i++;
                    } else {
                        if (len != 0)
                            len = lps[len - 1];
                        else {
                            lps[i] = 0;
                            i++;
                        }
                    }
                }
            }


            int strStr(string hay, string ne) {    //O(M)
                int n = hay.size();
                int m = ne.size();
        
                vector<int> lps(m);
                findlps(m, ne, lps);
        
                int i = 0, j = 0;
                while (i < n) {            // kmp algo
                    if (hay[i] == ne[j]) { // char matches
                        i++;
                        j++;
                    }
                    if (j == m) {
                        return i - j;
                    } // found pattern
                    else if (hay[i] != ne[j]) {
                        if (j != 0)
                            j = lps[j - 1];
                        else
                            i++; // kuch nhi kr skte
                    }
                }
        
                return -1;
            }
        };