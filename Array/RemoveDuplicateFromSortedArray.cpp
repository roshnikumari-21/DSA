
#include <bits/stdc++.h>
using namespace std;

// brute____________________ tc=O(nlogn)+O(n) ___________sc=O(N)

vector<int> uniqueSortedElements(const vector<int> &arr)
{
    set<int> st;

    // First pass to insert elements into the set
    for (int i = 0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }

    // Prepare output array to store sorted unique elements
    vector<int> uniqueElements;
    int index = 0; // Index for unique elements vector

    // Copy elements from the set back to the vector
    for (auto it = st.begin(); it != st.end(); ++it)
    {
        uniqueElements.push_back(*it);
    }

    return uniqueElements;
}

// optimised___________tc=O(n)___________sc=O(1)_____________________________________

int removeDuplicates(vector<int> &arr)
{
    if (arr.empty())
        return 0; 

    int i = 0; 

    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j] != arr[i])  //got a unique element
        {                    // Check if current element is different from the last unique
            i++;             // Move to the next position for unique element
            arr[i] = arr[j]; // Set the unique element
        }
    }

    return i + 1; // Return the count of unique elements
}