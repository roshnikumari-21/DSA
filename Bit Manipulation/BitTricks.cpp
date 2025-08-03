//clear the ith bit____________________

#include <bits/stdc++.h>
using namespace std;

int clearIthBit(int n, int i) {
    int mask = ~(1 << i);
    return n & mask;
}

//toggle the ith bit____________________


int toggleIthBit(int n, int i) {
    return n ^ (1 << i);
}


//remove the last ith set-bit (rightmosst)

int removeRightmostSetBit(int n) {
    return n & (n - 1);
}


//set the rightmost unset bit

int setBits(int N){
    if((N & (N+1))==0) return N;    //for numbers who have all bit set already
    return (N | (N+1));
}
