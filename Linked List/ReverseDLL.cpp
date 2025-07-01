//3 pointers...prev, cur, next...
//tc=O(N)    sc=O(1)


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