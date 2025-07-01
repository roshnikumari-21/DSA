#include <bits/stdc++.h>
using namespace std;


// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: 1 2 3 4 5 6 7

//brutee-->put all of them in a set, then store in vector and return it
//tc=O(nlogn)
//sc=O(n1+n2)--->to return the answer

//optimal-->two pointer approach


vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        } else {
            if (unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < n2) {
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while (i < n1) {
        if (unionArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}