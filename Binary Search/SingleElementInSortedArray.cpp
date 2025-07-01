//hello its 01:26am in the night and i am feeling sleepy coz...

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

//brute force________________
#include <bits/stdc++.h>
using namespace std;


int findSingleElement(vector<int>& arr) {
    int n = arr.size();
    
 
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // If the first element is different from the next one, return it
            if (arr[i] != arr[i + 1]) return arr[i];
        } else if (i == n - 1) {
            // If the last element is different from the previous one, return it
            if (arr[i] != arr[i - 1]) return arr[i];
        } else {
            // If the element is different from both its neighbors, return it
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]) return arr[i];
        }
    }
    
    return -1; // Should never reach here if input is valid
}


//optimal_____________________

//(even,odd) --->we are in left half , the required element is on right half
//(odd,even) ---->we are in right half, the required element is on left half
//check from 1 to n-2...so that to avoid bases



int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size();
    
    if (n == 1) return arr[0]; // If there is only one element, return it.
    
    // Checking the first and last elements separately
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2; // Start binary search from index 1 to n-2
    
    while (low <= high) {
        int mid = (low + high) / 2;

        // If mid element is the unique one
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        // If we are in the left part of the array
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || 
            (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        }
        // If we are in the right part
        else {
            high = mid - 1;
        }
    }
    
    return -1; // Should never reach here for valid input
}
