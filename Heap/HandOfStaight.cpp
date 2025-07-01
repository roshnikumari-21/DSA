// store freq of all lements in map
// sort the array

#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    int n = hand.size();

    if (n % groupSize != 0)
    {
        return false;
    }

    map<int, int> mp;
    for (int &handNumber : hand)
    {
        mp[handNumber]++;
    }

    while (!mp.empty())
    {
        int curr = mp.begin()->first; // smallest available card

        for (int i = 0; i < groupSize; i++)
        {
            if (mp[curr + i] == 0)
            {
                return false;
            }

            mp[curr + i]--;
            if (mp[curr + i] < 1)
            {
                mp.erase(curr + i);
            }
        }
    }

    return true;
}