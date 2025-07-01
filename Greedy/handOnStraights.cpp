#include <bits/stdc++.h>
using namespace std;


//use map for storing freq....form group and check

//tc=O(nlogn)->for map and O(n*grsize)

class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int gr) {
            int n = hand.size();
            if (n % gr != 0)
                return false; // early return
    
            map<int, int> mp;
            for (int i = 0; i < n; i++) {
                mp[hand[i]]++;
            }
    
            while (!mp.empty()) {
                int cur = mp.begin()->first;
                for (int i = 0; i < gr; i++) {
                    if (mp.find(cur + i) == mp.end())
                        return false;
                    mp[cur + i]--;
                    if (mp[cur + i] == 0)
                        mp.erase(cur + i);
                }
            }
    
            return true;
        }
    };