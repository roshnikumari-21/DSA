#include <bits/stdc++.h>
using namespace std;

//Return the minimum integer k such that she can eat all the bananas within h hours.

//k=banana/hr  , banana eating speed


//start=1, end=v[n-1] after sorting

class Solution {
    public:
          bool f(vector<int>&v,int n,int mid,int h){
            long long s=0;
            for(int i=0; i<n; i++){
                s+=(v[i]/mid);
                if(v[i]%mid) s++;
                
            }
            if(s<=h) return true;
            else return false;
          }
    
        int minEatingSpeed(vector<int>& v, int h) {
            long long sum=0;
             sort(v.begin(),v.end());
            int n=v.size();
            for(int i=0; i<n; i++){
                sum+=v[i];
            }
            int start=1,end=v[n-1],mid,ans=-1;
            while(start<=end){
                mid=start+(end-start)/2;
                if(f(v,n,mid,h)){ ans=mid; end=mid-1;}
                else start=mid+1;
            }
             return ans;
        }
    };