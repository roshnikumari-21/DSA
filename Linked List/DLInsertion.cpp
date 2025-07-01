#include <bits/stdc++.h>
using namespace std;

// // Function to insert a new node at given position in doubly linked list.


// class Solution {
//     public:
//       // Function to insert a new node at given position in doubly linked list.
//       Node *addNode(Node *head, int pos, int data) {
//           Node* temp=head;
//           Node* nw=new Node(data);
//           if(head==NULL) return nw;
          
//           while(pos--){
//               temp=temp->next;
//           }

//           Node* left=temp->next;
//           temp->next=nw;
//           nw->prev=temp;
          
//           nw->next=left;
//          if(left!=NULL) left->prev=nw;
//           return head;
//       }
//   };