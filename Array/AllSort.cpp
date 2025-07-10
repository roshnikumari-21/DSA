#include <bits/stdc++.h>
using namespace std;

// selection sort__________
// tc=O(n^2)....worst=O(n^2)

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minind])
                minind = j;
        }
        swap(arr[minind], arr[i]);
    }
}



// bubble sort_______________________________
// tc=O(n).....worst=O(n^2)

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    { // last element already get placed
        for (int j = 0; j < n - i - 1; j++)
        { // remember the index stop condn
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// bubble sort__with recursion___________________________________

void recurbs(vector<int> &arr, int ind)
{
    if (ind == 0)
        return;
    for (int j = 0; j < ind; j++)
    {
        if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
    }
    recurbs(arr, ind - 1);
}

void bubbleSort(vector<int> &arr, int n)
{
    recurbs(arr, n - 1);
}

// insertion sort_____________________________________________________
// tc=O(n)..........worst=O(n^2)

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// insertion sort with recursion_________________________________________________

class Solution
{
public:
    int n;
    void solve(vector<int> &arr, int ind)
    {
        if (ind == n)
            return;

        int key = arr[ind];
        int j = ind - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        solve(arr, ind + 1);
    }
    // Please change the array in-place
    void insertionSort(vector<int> &arr)
    {
        n = arr.size();
        solve(arr, 1);
    }
};

// merge sort___________
// tc=O(nlogn)_______worst=O(n^2)___________________sc=O(n)

//here instead of padding i can use simpley a[n1] and b[n2] and then 2 more while condn for boundaries...

class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        int i = 0, j = 0, k = l;
        int n1 = m - l + 1;      //length of first half
        int n2 = r - m;         //length of second half
        int a[n1 + 1];
        int b[n2 + 1];
        for (int i = 0; i < n1; i++)
        {
            a[i] = arr[l + i];
        }

        a[n1] = INT_MAX;

        for (int i = 0; i < n2; i++)
        {
            b[i] = arr[m + 1 + i];
        }
        b[n2] = INT_MAX;

        while (i < n1 || j < n2)
        {
            if (a[i] <= b[j])
            {
                arr[k] = a[i];
                i++;
            }
            else
            {
                arr[k] = b[j];
                j++;
            }
            k++;
        }
    }



public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};



// quick sort___________________________________
// tc=O(nlogn)_______worst=O(n^2)_______sc=O(logn)-->recursion depth avg..
//now its ascending...but with minor tweaks it will be descending too...
//pivot can be any random element of your choice---->pick it up and place it in its corrcect place


class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }


    
public:
//This function returns the final position of the pivot after partitioning.
    int partition(int arr[], int low, int high)
    {
        int key = arr[low];
        int j = low + 1;
        int i = low;
        while (j <= high)
        {
            if (arr[j] < key)
            {
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        swap(arr[i], arr[low]);
        return i;
    }
};

// heap sort____________________________________________
// tc=O(nlogn)_____________________sc=O(1)_________

//ascending order.............................

//max-heapify
void heapify(vector<int>& arr, int n, int i) {    //heap-down
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build a max-heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);       // Move current root to end
        heapify(arr, i, 0);         // Heapify the reduced heap
    }
}
