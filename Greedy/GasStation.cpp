//unique solution exist, thus no need to coomplete the entire cycle..
// given two integer arrays A and B of size N. There are N gas stations along a circular route,
// where the amount of gas at station i is A[i].

// You have a car with an unlimited gas tank and it costs B[i] of gas to travel from
// station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int totgas=0,totcost=0;
    int n=A.size();
    for(auto gas : A){
        totgas+=gas;
    }
    for(auto cost: B){
        totcost+=cost;
    }
    if(totcost>totgas) return -1;   //early return

     int ind=0,curgas=0;
     
    for(int  i=0;  i<n;  i++){
       curgas+=(A[i]-B[i]);
       if(curgas<0) {
           ind=i+1;
           curgas=0;
       }       
    }
    
    return ind;
}

