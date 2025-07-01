#include <bits/stdc++.h>
using namespace std;


//Given an integer array nums, return the number of reverse pairs in the array.
//nums[i] > 2 * nums[j].


// Input: nums = [1,3,2,3,1]
// Output: 2

//same as inverse count.....

//brute______________________tc=O(n*n)_____________________sc=O(1)____________________________
//two loops check for each pair

//optimal----> merge sort .....implementation first


class Solution {
    public:
        int n;
        int cnt;     //global variables
        void merge(int left, int mid, int right, vector<int>& a, int n) {
    
            int n1 = mid - left + 1;
            int n2 = right - mid;
            vector<int> temp1(n1);
            vector<int> temp2(n2);
    
            for (int i = 0; i < n1; i++) {
                temp1[i] = a[left + i];
            }
    
            for (int i = 0; i < n2; i++) {
                temp2[i] = a[mid + 1 + i];
            }
            
            //counting actually pairs....
            int i = 0, j = 0;
            while (i < n1 && j < n2) {
                if (temp1[i] > (2*1LL*temp2[j])) {
                    cnt += (n1 - i);
                    j++;
                } else {
                    i++;
                }
            }
    
            i = 0, j = 0;
            int k = left;
            while (i < n1 && j < n2) {
                if (temp1[i] <= temp2[j]) {
                    a[k] = temp1[i];
                    i++;
                } else {
                    a[k] = temp2[j];
                    j++;
                }
                k++;
            }
    
            // Copy the remaining elements of lefta[], if any
            while (i < n1) {
                a[k] = temp1[i];
                i++;
                k++;
            }
    
            // Copy the remaining elements of righta[], if any
            while (j < n2) {
                a[k] = temp2[j];
                j++;
                k++;
            }
        }
    
        void mergesort(int left, int right, vector<int>& a, int n) {
            if (left >= right)
                return;
            int mid = (left + right) / 2;
            mergesort(left, mid, a, n);
            mergesort(mid + 1, right, a, n);
            merge(left, mid, right, a, n);
        }
    
        int reversePairs(vector<int>& a) {
            n = a.size();
            mergesort(0, n - 1, a, n);
            return cnt;
        }
    };