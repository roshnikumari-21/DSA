//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//MIK

//Input: s = "aacecaaa"
//Output: "aaacecaaa"

#include <bits/stdc++.h>
using namespace std;

//brute--- mle_______________________

//find the longest valid palindrome from start of s...rest are culprit
//tc=O(n^2)   sc=O(n)

class Solution {
    public:
        string shortestPalindrome(string s) {
            int n = s.size();
            string rev = s;           //make a reversed string
            reverse(rev.begin(), rev.end());
            for (int i = 0; i < n; i++) {
                string str = s.substr(0, n - i);    
                string str2 = rev.substr(i);   //substr index i to end
                if (str == str2) {
                    return rev.substr(0, i) + s;
                }
            }
    
            return "";    //it never reaches here ..
        }
    };


    //using cmp for memory comparisons______________________

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s; // make a reversed string
        reverse(rev.begin(), rev.end());
        for (int i = 0; i < n; i++) {

            if (!memcmp(s.c_str(), rev.c_str() + i, n - i)) {
                return rev.substr(0, i) + s;
            }
        }

        return ""; // it never reaches here ..
    }
};



    //best approach ____using kmp___________________
    //we basically find the longest proper prefix in s which matches the suffix in rev
    // tc= O(n) sc=O(n)

    class Solution {
        public:
            int n;
            void find(vector<int>& lps, string s) {  //lps finding algo
                int m = s.size();
                lps[0] = 0;
                int len = 0, i = 1;
                while (i < m) {
                    if (s[i] == s[len]) {
                        len++;
                        lps[i] = len;
                        i++;
                    } else {
                        if (len != 0) {
                            len = lps[len - 1];
        
                        } else {
                            lps[i] = 0;
                            i++;
                        }
                    }
                }
            }


            string shortestPalindrome(string s) {     
                n = s.size();        
                string rev = s;
                reverse(rev.begin(), rev.end());
                string temp = s + "#" + rev;
                int m = temp.size();
                vector<int> lps(m, 0);
                find(lps, temp);
        
                int maxi = lps[m - 1];
                cout << maxi << " ";
                return (rev.substr(0, n - maxi) + s);
            }
        };