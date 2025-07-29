// Input: start = 10, goal = 7
// Output: 3

//tell how many bits need to flipped to get start to goal

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int val = start ^ goal;   //to get how many bits are not same  //O(1)
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (((1 << i) & val) != 0)
                ans++;
        }
        return ans;
    }
};