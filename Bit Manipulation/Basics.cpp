

#include <bits/stdc++.h>
using namespace std;

//tc=log(n)   sc=log(n)

string convert2Binary(int n) {
    string res = "";
    while (n > 0) {
        if (n % 2 == 1)
            res += '1';
        else
            res += '0';
        n = n / 2;
    }
    
    reverse(res.begin(), res.end());
    return res;
}



//______tc=O(len)_____________sc=O(1)________________


int convert2Decimal(string s) {
    int len = s.length();
    int power = 1;
    int num = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '1') {
            num += power;
        }
        power *= 2;
    }

    return num;
}

//________________________________________________________________________________

string getOnesComplement(string binary) {
    string ones = "";
    for (char bit : binary) {
        ones += (bit == '0') ? '1' : '0';
    }
    return ones;
}



//______ignore for now_______________________________________________________________________




string getTwosComplement(string ones) {  //we are taking ones cmplemeent her
    string twos = ones;              // Make a copy of the string
    int n = ones.length();           // Get the length

    // Traverse from the end and add 1
    for (int i = n - 1; i >= 0; i--) {
        if (ones[i] == '0') {
            twos[i] = '1';           // Add 1 to the first '0' from right
            break;
        } else {
            twos[i] = '0';           // Carry over if it's '1'
        }
    }

    return twos;
}

//mera wala method___________________________________________

string computeTwosComplement(string bin) {
    int n = bin.size();
    bool foundOne = false;

    // Start from end, copy bits until first '1' is found
    for (int i = n - 1; i >= 0; i--) {
        if (foundOne) {
            // Flip the bits after the first '1'
            bin[i] = (bin[i] == '1') ? '0' : '1';
        } else if (bin[i] == '1') {
            foundOne = true;  // mark the first '1'
        }
    }

    // if no 1 found (i.e. all 0s), return "1" + bin
    if (!foundOne) {
        return "1" + bin;
    }

    return bin;
}
