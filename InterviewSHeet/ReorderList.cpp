#include <bits/stdc++.h>
using namespace std;


// Given a singly linked list

//     L: L0 → L1 → … → Ln-1 → Ln,
// reorder it to:

//     L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// You must do this in-place without altering the nodes’ values


//codewithMIK

//brute_____________________________
//reverse the last half of array
//then do connections.....jo ki mujhe smjh nhi aayaaa


//better________tc=O(N)_________sc=O(N )________________


        // class Solution {
        // public:
        //     void reorderList(ListNode* head) {
        //         stack<ListNode*>st;
        //         ListNode* temp=head;
        //         while(temp!=NULL){
        //             st.push(temp);
        //             temp=temp->next;
        //         }

        //         ListNode* curr=head;
        //         ListNode* topnod;
        //         int k=st.size()/2;
        //         while(k--){
        //             topnod=st.top();
        //             st.pop();
        //             temp=curr->next;
        //             curr->next=topnod;
        //             topnod->next=temp;
        //             curr=temp;
        //         }
        //         curr->next=NULL;
        //         return;
                
        //     }
        // };


//optimal____________________________________________________
//using recursion

//tc=O(n) sc=O(1)___________


//isko baad me smjh lena ...
