// Number of inversions in an array can be defined as the number of pairs of ‘i’, ‘j’
// such that ‘i’ < ‘j’ and ‘A[i]’ > ‘A[j]’.

// You must return the number of inversions in the array.

// naive solution____________tc=O(n^2)_________sc=O(1)___________
// by using two loops

// optimised one_________tc=O(nlog(n))_______________________________

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;   //global variable
void merge(int left, int mid, int right, vector<int> &a, int n)    
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> temp1(n1);
    vector<int> temp2(n2);

    for (int i = 0; i < n1; i++)    //O(N1)
    {
        temp1[i] = a[left + i];
    }

    for (int i = 0; i < n2; i++)    //O(N2)
    {
        temp2[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2)    //main parttt
    {
        if (temp1[i] > temp2[j])
        {
            cnt += (n1 - i);
            j++;
        }
        else
        {
            i++;
        }
    }

    i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (temp1[i] <= temp2[j])
        {
            a[k] = temp1[i];
            i++;
        }
        else
        {
            a[k] = temp2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of lefta[], if any
    while (i < n1)
    {
        a[k] = temp1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of righta[], if any
    while (j < n2)
    {
        a[k] = temp2[j];
        j++;
        k++;
    }
}



void mergesort(int left, int right, vector<int> &a, int n)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergesort(left, mid, a, n);
    mergesort(mid + 1, right, a, n);
    merge(left, mid, right, a, n);
}

int numberOfInversions(vector<int> &a, int n)
{
    mergesort(0, n - 1, a, n);   //O(NlogN)
    return cnt;
}