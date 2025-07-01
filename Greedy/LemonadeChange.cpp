#include <bits/stdc++.h>
using namespace std;

//tc=o(N)
class Solution {
    public:
        bool lemonadeChange(vector<int>& bil) {
            int n=bil.size();
            int five=0,ten=0,twe=0;
            for(int i=0; i<n; i++){
                if(bil[i]==5) five++;
                else if(bil[i]==10){
                    ten++;
                    if(five>0) five--;
                    else return false;
                }
                else {
                    twe++;
                    if(ten>0 && five>0) {ten--; five--;}
                    else if(five>2) five-=3;
                    else return false;
                }
            }
            return true;
        }
    };