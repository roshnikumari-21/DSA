#include <bits/stdc++.h>
using namespace std;


// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000


//brute_____________________________
//merge both and find the median
//for even=N/2, N/2 -1
//tc=O(N1+N2)   sc=O(N1+n2)





//better___tc=O(N+N)___________sc=O(1)____________________________________

//using only pointers and will not be storing them....

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    int n = n1 + n2;
    int ind1 = n / 2;
    int ind2 = n / 2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        } else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }

    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1) return ind1el;     //for odd
    return (ind1el + ind2el) / 2.0;
}


//binary search approach_____optimal__________________________________________________
//do binary search on shorter array to reduce time complexity
//tc=log(n1)



// Time   	O(log(min(n1, n2)))
// Space	O(1)


double median(vector<int>& a, vector<int>& b) {   //a ko chota assume krte hue
    int n1 = a.size();
    int n2 = b.size();

    if (n1 > n2) return median(b, a);  // Ensure a is the smaller array

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high) {
        int mid1 = (low + high)/2 ;   //divided by 2
        int mid2 = left - mid1;     //it is the index for b vector

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];

        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }

    return 0;
}
