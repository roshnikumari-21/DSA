//each process is arriving at time 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      long long solve(vector<int>& bt) {
          sort(bt.begin(),bt.end());
          int sum=0;
          int tsum=0;
          int n=bt.size();
          for(int i=0; i<n-1; i++){
              sum+=bt[i];
              tsum+=sum;
          }
          return floor(tsum/n);
      }
  };
  