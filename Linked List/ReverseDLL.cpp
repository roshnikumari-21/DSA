// 3 pointers...prev, cur, next...
// tc=O(N)    sc=O(1)

// class Solution {
//     public:
//       // Function to reverse a doubly linked list
//       DLLNode* reverseDLL(DLLNode* head) {
//           DLLNode* cur=head;
//           DLLNode* prevv=NULL;
//           DLLNode* temp;
//           while(cur!=NULL){
//               temp=cur->next;
//               cur->next=prevv;
//               cur->prev=temp;
//               prevv=cur;
//               cur=temp;
//           }

//           return prevv;
//       }
//   };

// u can do it with 2 pointers also, curr and last

// Node *reverseDLL(Node *head)
// {
//
//     if (head == NULL || head->next == NULL)
//         return head;

//     Node *last = NULL;
//     Node *curr = head;
//     while (curr != NULL)
//     {
//         last = curr->prev;
//         curr->prev = curr->next;
//         curr->next = last;

//         curr = curr->prev;
//     }
//     return last->prev;
// }
