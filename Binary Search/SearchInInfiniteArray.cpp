#include <bits/stdc++.h>
using namespace std;


int getValue(int index) {
    
     int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    if (index < 0 || index >= sizeof(arr)/sizeof(arr[0])) {
        return INT_MAX; // simulate infinity by returning a large number
    }
    return arr[index];
}


int searchInInfiniteArray(int target) {
    int start = 0, end = 1;

    
    while (getValue(end) < target) {
        start = end + 1;
        end = end * 2;  // exponentially increase end
        // To prevent potential overflow:
        if (end > INT_MAX / 2) break; // or handle as needed
    }

    // Step 2: Binary search within start and end
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int mid_val = getValue(mid);

        if (mid_val == target) {
            return mid; // target found
        } else if (mid_val < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1; // target not found
}

int main() {
    int target = 15;
    int index = searchInInfiniteArray(target);
    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }
    return 0;
}