#include <bits/stdc++.h>
using namespace std;


//brute________tc=O(N^2)_______________________________


int countSubarraysWithXOR(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int xorVal = 0;
        for (int j = i; j < n; j++) {
            xorVal ^= arr[j];
            if (xorVal == k)
                count++;
        }
    }

    return count;
}


//optimal___________________tc=O(NlogN)_________________sc=O(N)_______________________________


int subarraysWithSumK(vector<int> &a, int k) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;  // Initialize with prefix XOR 0 having count 1

    int cnt = 0;

    for (int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i];
        int x = xr ^ k;

        cnt += mpp[x];  // Count of previous prefix XORs that would satisfy the condition
        mpp[xr]++;      // Store the current prefix XOR
    }

    return cnt;
}

