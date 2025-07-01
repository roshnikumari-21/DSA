#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:
	long long f(int a,int n,int limit){
	    long long res=1;
	    while(n--){
	        res=(res*1LL*a);
	        if(res>limit) return res;
	    }
	    return res;
	    
	}
	int NthRoot(int n, int m)
	{
	    int start=0,end=m,mid;
      while(start<=end){
          mid=start+(end-start)/2;
          if(f(mid,n,m)==m) { return mid;}
          else if(f(mid,n,m)<m)  start=mid+1;
          else end=mid-1;
      }
      return -1;
	}  
}; 