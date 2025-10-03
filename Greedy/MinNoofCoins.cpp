//coins[]={1,5,10,20,50,100}
//v=47
//greedy only works when the sum of two smaller coins do not exceed its next coin
//eg. here 1+5 is smaller than 10
//start iterating from end of coins vector,...u know it 

//tc= O(n)


#include <bits/stdc++.h>
using namespace std;

vector<int> findMinCoins(int amount, vector<int> &coins) {
    vector<int> result;
    sort(coins.rbegin(), coins.rend());
    
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }
   return result;
}

