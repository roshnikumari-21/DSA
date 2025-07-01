//Given a sorted array, arr[] and a number target, you need to find the number
// of occurrences of target in arr[]. 



//brute_________________________________________

#include <bits/stdc++.h>
using namespace std;

void findFirstAndLastOccurrence(vector<int>& arr, int n, int x) {
    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last << endl;
}

//optimal_________using lb and ub______________not recommended by me_____________________________________________
//tc=O(log(n))            sc=O(1)


#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            // look for more small index on left
            high = mid - 1;
        } else {
            low = mid + 1; // look for right
        }
    }
    return ans;
}

int upperBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            // look for more small index on left
            high = mid - 1;
        } else {
            low = mid + 1; // look for right
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int lb = lowerBound(arr, n, k);
    if (lb == n || arr[lb] != k) return {-1, -1};
    return {lb, upperBound(arr, n, k) - 1};
}



//most optimal code written from scratch____________________________________


#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // keep searching on the left side
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return first;
}

int findLastOccurrence(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // keep searching on the right side
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return last;
}

pair<int, int> findFirstAndLastPosition(vector<int>& arr, int x) {
    int n = arr.size();
    int first = findFirstOccurrence(arr, n, x);
    int last = findLastOccurrence(arr, n, x);
    return {first, last};
}