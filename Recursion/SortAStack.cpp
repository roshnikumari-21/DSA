#include <bits/stdc++.h>
using namespace std;

// Stack: 11 2 32 3 41
// Output: 41 32 11 3 2


//tc=O(n^2)
//sc=O(N)-->recursive depth

stack<int> s;   //global

void insert(int val)
{
    if (s.empty() || s.top() <= val)   //sahi order me hai
    {
        s.push(val);
        return;
    }

    int topi = s.top();      //nhi to top element ko bahar nikalo 
    s.pop();
    insert(val);
    s.push(topi);               //aur fir val ko daalkr fir daaalo
}


void sorti()      //main...
{
    if (s.empty())    //base case
        return;
        
    int topi = s.top();
    s.pop();
    sorti();
    insert(topi);
}