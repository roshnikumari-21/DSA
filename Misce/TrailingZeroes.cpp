// Given an integer A, return the number of trailing zeroes in A!.

//using the same jee wala formula...
//5 ki jitni total multiples hongi utni zereos


#include <bits/stdc++.h>
using namespace std;


int trailingZeroes(int a) {
    
    int res=1,fi=5,sum=0;
    
    while(res>0){
        res=a/fi;
        fi*=5;
        sum+=res;
    }
    return sum;
    
    
}
