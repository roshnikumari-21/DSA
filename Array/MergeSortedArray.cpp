//Merge nums1 and nums2 into a single array sorted in non-decreasing order.

//without using extra space

#include <bits/stdc++.h>
using namespace std;






//brute______tc=O(n+m)_______________sc=O(N+m)_________________________________________


void merge(long long arr1[], long long arr2[], int n, int m) {
    long long arr3[n + m];  // Temporary array to store merged elements

    int left = 0;
    int right = 0;
    int index = 0;

    // Merge the arrays until one of them is exhausted
    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++;
        } else {
            arr3[index] = arr2[right];
            right++;
        }
        index++;
    }

    // Copy remaining elements of arr1, if any
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // Copy remaining elements of arr2, if any
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Copy back to arr1 and arr2 from arr3
    for (int i = 0; i < n + m; i++) {
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
}







//optimal________tc=O(M+N)_________sc=O(1)__________besttt___________________________________________-




class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          
            int i=m-1;
            int j=n-1;
            int k=n+m-1;
    
            while(j>=0){
                if(i>=0 &&  nums1[i]>nums2[j]){
                    nums1[k]=nums1[i];
                    k--;  i--;
                }
                else{
                    nums1[k]=nums2[j];
                    k--; j--;
                }
            }
    
            return;
    
            
        }
    };



    //another way______________O(n+m)+O(nlogn)+O(mlogm)____________________________________________
    //sc=O(1)



    class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Function to merge the arrays.

        int left = m - 1;
        int right = 0;

        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);

        int j = 0;

        for (int i = m; i < (nums1.size()); i++) {
            nums1[i] = nums2[j];
            j++;
        }

        return;
    }
};


//____Gap Algorithm (used in Shell Sort)_________________________
//gap should be on (N+M)/2 distance apart left and right pointers
//whenever one of the pointers go out of the boundary , reduce the gap by dividing it by 2.

//sc=O(1)


class Solution {
public:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1,
                       int ind2) {
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
    }
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int len = (n + m);
        int gap = (len / 2) + (len % 2);
        while (gap > 0) {          //O(len*log(len))
            int left = 0;  
            int right = left + gap;
            while (right < len) {           //O(len)
                if (left < n && right >= n) {
                    swapIfGreater(nums1, nums2, left, right - n);
                } else if (left >= n) {           //both in second arr
                    swapIfGreater(nums2, nums2, left - n, right - n);
                } else {                             //both in first arr
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }
            if (gap == 1)
                break;
            else
                gap = (gap / 2) + (gap % 2);
        }

        for (int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
    }
};