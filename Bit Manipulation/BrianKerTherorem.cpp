#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << "Set Bits: " << countSetBits(n) << endl;
}


//Each step removes the rightmost set bit, reducing the number by a power of 2.


//__________________other ways_________good way_________

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}
