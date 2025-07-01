#include <bits/stdc++.h>
using namespace std;


void reverseArray(int arr[], int start, int end) {  
    // Base case: If start index is greater than or equal to end index, stop recursion  
    if (start >= end) {  
        return;  
    }  

    // Swap the elements at the start and end  
    swap(arr[start], arr[end]);  

    // Recursive call  
    reverseArray(arr, start + 1, end - 1);  
}  