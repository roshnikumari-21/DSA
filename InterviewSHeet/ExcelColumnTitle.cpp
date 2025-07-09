#include <bits/stdc++.h>
using namespace std;


//Given a positive integer A, return its corresponding column title as appear in an Excel sheet.
//eg: 28-> AB

string convertToTitle(int A) {
   
    string ans="";
    while(A>0){
         A--;        //for making it 0 based indexing
        int rem=A%26;
        char ch=rem+'A';
        ans=ch+ans;
        A=A/26;
        
    }
    return ans;
}
