#include <bits/stdc++.h>
using namespace std;


//BRUTE__________tc=O(2n)___________sc=O(N)


vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();
    int hash[n + 1] = {0};

    // Count occurrences of each number
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    int repeating = -1, missing = -1;

    // Find the repeating and missing number
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
            missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }

    return {repeating, missing};
}


//better approach_____mathss____________
//tc=O(N)______sc=O(1)



vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size();

    // Expected sum and sum of squares
    long long SN = (n * (n + 1)) / 2;  
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;

    // Actual sum and sum of squares from array
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // x = repeating, y = missing
    long long val1 = S - SN;        // x - y   // actual- formula
    long long val2 = S2 - S2N;      // x^2 - y^2

    val2 = val2 / val1;             // x + y

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}



//xor method_______tc=O(N)___________sc=O(1)__________________________


vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size();
    int xr = 0;

    // Step 1: XOR all array elements and numbers from 1 to n
    for (int i = 0; i < n; i++) {    //O(N)
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    // Step 2: Find rightmost set bit (distinguishing bit)
    int bitNo = 0;
    while (1) {                            
        if ((xr & (1 << bitNo)) != 0) {
            break;
        }
        bitNo++;
    }

    // Step 3: Divide elements into two buckets and XOR separately
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {                  //O(N)
        if ((a[i] & (1 << bitNo)) != 0) {   //the bit is 1
            one = one ^ a[i];
        } else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if ((i & (1 << bitNo)) != 0) {
            one = one ^ i;
        } else {
            zero = zero ^ i;
        }
    }

    // Step 4: Determine which is missing and which is repeating
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};  // zero is repeating
    return {one, zero};                // one is repeating
}



