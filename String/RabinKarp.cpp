#include <bits/stdc++.h>
using namespace std;

// we will be using hash code
// sliding is known as rolling hash function
// spurious hits --->the hash value is matching but the pattern is not matching
// tc=O(n-m+1) ,in worst case it could take O(nm)--->due to weak hash function



class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        if (m > n)
            return -1;        //early return

        const int base = 10;

        long long hash_needle = 0, hash_window = 0, power = 1;
        for (int i = 0; i < m; ++i)
        {
            hash_needle = hash_needle * base + (needle[i] - 'a');
            hash_window = hash_window * base + (haystack[i] - 'a');            
                power *= base;
        }

        for (int i = 0; i <= n - m; ++i)
        {
            if (hash_window == hash_needle)
            {
                if (haystack.substr(i, m) == needle)
                    return i;
            }
            if (i < n - m)
            {
                hash_window = (hash_window - (haystack[i] - 'a') * power) * base + (haystack[i + m] - 'a');
            }
        }

        return -1;
    }
};
