//brute__very much brute is to linear search on every number_____________________________
//tc=O(N^2)-->for each number i am checking

//better---> using  hashing____________________________________
//tc=O(N)+O(N)   sc=O(N)


#include <bits/stdc++.h>
using namespace std;


int findMissingNumber(int arr[], int n) {
    int hash[n + 1] = {0};

    // Mark the present numbers
    for (int i = 0; i < n - 1; i++) {
        hash[arr[i]] = 1;
    }

    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0)
            return i;
    }

    return -1; // Should not reach here
}




//optimal________________tc=O(N)____________sc=O(1)


int findMissingNumber(int arr[], int n) {
    // Calculate the expected sum of numbers from 1 to n
    int totalSum = n * (n + 1) / 2;

    // Calculate the actual sum of elements in the array
    int actualSum = 0;
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    // The missing number is the difference
    return totalSum - actualSum;
}
