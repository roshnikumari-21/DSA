// dont use another new array
// left rotate by one place

#include <bits/stdc++.h>
using namespace std;


//tc=O(n)   sc=O(1)

void rotateArrayLeftByOne(vector<int> &arr)
{
    if (arr.empty())
        return; // Handle empty array

    int n = arr.size(); // Get the size of the array
    int temp = arr[0];  // Store the first element

    // Shift elements to the left
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1]; // Move each element one position to the left
    }

    arr[n - 1] = temp; // Set the last element to the stored first element
}

//left rotate by d places_______________________________________________________________

//brute

class Solution {
  public:
    void leftRotate(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> v;
        v = arr;
        k = k % n;
        for (int i = 0; i < n; i++)
        {
            int ind = (i - k+n) % n;
            v[ind] = arr[i];
        }
        arr = v;
    }
};



//optimal______________________tc=O(2n)______________________sc=O(1)

//first reverse k elements, then from k to end, then whole array
//observation based

void RotateLeftByK(vector<int>& arr, int n, int k) {    //dhyan dena....
    // Adjust k for cases where k >= n  
    k = k % n;  

    // Reverse the first k elements  
    reverse(arr.begin(), arr.begin() + k);  
    
    // Reverse the remaining n-k elements  
    reverse(arr.begin() + k, arr.end());  
    
    // Reverse the whole array  
    reverse(arr.begin(), arr.end());  
}  