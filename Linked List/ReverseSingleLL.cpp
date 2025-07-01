#include <bits/stdc++.h>
using namespace std;

//iterative code_______________________________________

// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *temp = head;
//         ListNode *prev = NULL;
//         ListNode *nxt;
//         while (temp != NULL)
//         {
//             nxt = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp = nxt;
//         }
//         return prev;
//     }
// };


//recursive code_________________tc=O(N)____sc=O(N) due to recursive stack space_____________________________________________

 

// class Solution {
//     public:
          
//         ListNode* reverseList(ListNode* head) {
//             if(head==NULL || head->next==NULL) return head;         //base case  
//             ListNode* nwh=reverseList(head->next);
//             ListNode* front=head->next;
//             front->next=head;
//             head->next=NULL;
//             return nwh;
    
//         }
//     };