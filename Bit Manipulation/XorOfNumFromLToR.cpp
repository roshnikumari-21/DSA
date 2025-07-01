//You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].


//brute_________tc=o(len)_______sc=O(1)
//apply loops and find xor from l to r


//optimal__________tc=O(1)_____________sc=O(1)______________________

#include <bits/stdc++.h>
using namespace std;

//raat lo isse 

class Solution {
    public:
      int f(int n){
          if(n%4==1) return 1;
          if(n%4==2) return (n+1);
          if(n%4==3) return 0;
          else return n;
      }
      int findXOR(int l, int r) {
          return f(l-1)^f(r);
      }
  };
  