#include <bits/stdc++.h>
using namespace std;

//tc=O(N*C)

class Solution
{
public:
    int pageFaults(int n, int c, int pages[])
    {
        unordered_set<int> s;       // to store current pages in memory
        unordered_map<int, int> mp; // to store the last used index of each page

        int pgfault = 0;

        for (int i = 0; i < n; ++i)
        {
            // If space is available in memory
            if (s.size() < c)
            {
                if (s.find(pages[i]) == s.end())
                {
                    pgfault++;
                    s.insert(pages[i]);
                }
                // update the recent use index
                mp[pages[i]] = i;
            }
            else
            {
                // Memory is full - apply LRU
                if (s.find(pages[i]) == s.end())
                {
                    int lru = INT_MAX, val;
                    for (auto it : s)
                    {
                        if (mp[it] < lru)
                        {
                            lru = mp[it];
                            val = it;
                        }
                    }

                    // Remove least recently used
                    s.erase(val);

                    // Insert the current page
                    s.insert(pages[i]);

                    pgfault++;
                }
                // Update the recent use index
                mp[pages[i]] = i;
            }
        }
        return pgfault;
    }
};