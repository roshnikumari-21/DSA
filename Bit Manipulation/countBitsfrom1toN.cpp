//burite-->count for every bit form 1 to n one by onw using loop
//tc=O(nlogn)

//optimal===>  observe pattern
//again revise it..

#include <bits/stdc++.h>
using namespace std;


int larpow(int n){     //give the max power of 2 within N
    int x=0;    
    while((1<<x)<=n){        
        x++;
    }
    return x-1;       //return 3 if n is 11
}

int countSetBits(int N)
{
    if(N==0) return 0;   //base case
    int x=larpow(N);
    int y=x*(1<<(x-1));   // us power se pehle ki saari bits
    int z=N-(1<<x);    //first bit of bache hua number ka count
    return 1+z+y+countSetBits(z);      //recursion
}