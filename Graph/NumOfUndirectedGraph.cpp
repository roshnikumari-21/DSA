//2 ki power nC2
//and we are talking about labeled graph
//a graph of n vertices can have upto nC2 edges..


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      long long count(int n) {
          long long r=n*(n-1)/2;
          long long ans=pow(2,r);
          return ans;
      }
  };