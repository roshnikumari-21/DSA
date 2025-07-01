 //tc=O(N)--->although runs only for n/2
 //sc=O(1)---->only two pointers fast and slow..


// class Solution {
//     public:
//         ListNode* middleNode(ListNode* head) {
//             ListNode* slow=head;
//             ListNode* fast=head;
//             while( fast!=NULL &&   fast->next!=NULL  ){
//                 slow=slow->next;                
//                 fast=fast->next->next;
                
//             }
//             return slow;
            
//         }
//     };

