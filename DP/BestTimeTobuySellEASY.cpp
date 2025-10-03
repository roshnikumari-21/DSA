#include <bits/stdc++.h>
using namespace std;


// You want to maximize your profit by choosing a single day to buy one stock and choosing a different 
// day in the future to sell that stock.

class Solution {
    public:       
    
        int maxProfit(vector<int>& arr) {
            int n=arr.size();
            int ans=0;
            int mini=arr[0];
            int pro=0;
            for(int i=1; i<n; i++){
                pro=max(pro,arr[i]-mini);
                mini=min(mini,arr[i]);
            }
            return pro;       
            
        }
    };