// A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly
//  decreasing.

//just use two  lis dp one for forward, other for backward....


#include <bits/stdc++.h>
using namespace std;


int longestBitonicSubsequence(vector<int>& arr, int n)
{  
	vector<int>dp1(n,1);     //for increasing from start
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[i]>arr[j] && dp1[i]<1+dp1[j] ) dp1[i]=1+dp1[j];
		}
	}

	vector<int>dp2(n,1);         //for decreasing from end
	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>i; j--){
			if(arr[i]>arr[j] && dp2[i]<1+dp2[j] ) dp2[i]=1+dp2[j];
		}
	}

	int maxi=1;
	for(int i=0; i<n; i++){
		maxi=max(maxi,(dp1[i]+dp2[i]-1));   //coz 1 guy is common
	}

	return maxi;    



}
