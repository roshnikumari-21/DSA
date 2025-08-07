//euclidean algo states:-
//mera chota wala gcd ka code

#include <bits/stdc++.h>
using namespace std;

int calcGCD(int n, int m){
    if(m==0) return n;
    else calcGCD(m,n%m);
}




//gcd(a,b)=gcd(a-b,b) = gcd(a,b-a)


//armstrong number
//eg. 153 ----> sum of cube of every digit=original number


//reverse a number___________________________________________________________


int reverseNumber(int num) {
    int rev = 0;
    
    while (num != 0) {
        int digit = num % 10;       // Get the last digit
        rev = rev * 10 + digit;     // Append it to reversed number
        num /= 10;                  // Remove the last digit
    }
    
    return rev;
}



//print all divisors_____________________________________________
//tc=O(sqrt(n))+O(dlogd)

void printDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end()); // To print in sorted order

    cout << "Divisors of " << n << " are: ";
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;
}

//power_________________________________



double bin(double x, long long n) {    //x is base, and n is power
    double res = 1;
    while (n) {
        if (n % 2) {
            res *= x;  // Multiply the result by x if n is odd
            n--;       // Reduce n by 1 (to make it even)
        } else {
            x *= x;    // Square x to reduce the power
            n /= 2;    // Divide the power by 2
        }
    }
    return res;
}