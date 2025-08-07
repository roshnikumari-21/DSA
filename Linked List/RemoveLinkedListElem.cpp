// Given the head of a linked list and an integer val, remove all the nodes of the linked list 
// that has Node.val == val, and return the new head.

//singly linked list
//tc=O(N)______sc=O(1)

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* dm = new ListNode(-1);
//         ListNode* temp = head;

//         ListNode* cur = dm;
//         while (temp != NULL) {
//             if (temp->val != val) {
//                 cur->next = temp;
//                 cur = cur->next;
//             }
//             temp = temp->next;
//         }
//         cur->next = NULL;
//         return dm->next;
//     }
// };


