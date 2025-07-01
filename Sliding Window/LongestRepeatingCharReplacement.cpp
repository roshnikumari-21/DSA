#include <bits/stdc++.h>
using namespace std;

// length- maxfrequency_____________>how many char need to be changed



//brute____________tc=O(N^2)______________________

int longestSubstringWithLimit(string s, int k) {
    int n = s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        vector<int> hash(26, 0);
        int maxFreq = 0;

        for (int j = i; j < n; j++) {
            hash[s[j] - 'a']++;
            maxFreq = max(maxFreq, hash[s[j] - 'a']);

            int changes = (j - i + 1) - maxFreq;

            if (changes <= k) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                break;
            }
        }
    }

    return maxLen;
}


// optimal_____________________


class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int maxi = 0, maxf = 0, i = 0, j = 0;
        vector<int> hash(26, 0);
        while (j < n)
        {
            hash[s[j] - 'A']++;
            maxf = max(maxf, hash[s[j] - 'A']);

            while ((j - i + 1) - maxf > k)   
            {
                hash[s[i] - 'A']--;
                i++;
            }
            if (((j - i + 1) - maxf) <= k)
                maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};