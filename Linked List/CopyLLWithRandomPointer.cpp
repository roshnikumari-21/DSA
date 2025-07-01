// A deep copy is a type of copy where a new object is created, and all of its elements
//   (including dynamically allocated memory or referenced objects) are recursively copied.
//    This ensures that changes to the original object do not affect the copied object.

// In contrast, a shallow copy only copies the references or pointers to the data,
//  meaning both objects share the same memory location for dynamic data.

// in this queest we have to make a deep copy

// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// tc=O(2n)   //sc=O(n)+O(n), one for map one for creating the answer

// class Solution {
//     public:
//         Node* copyRandomList(Node* head) {
//             Node* temp=head;
//             map<Node*,Node*>mp;
//             while(temp!=NULL){
//                 Node* nwnod=new Node(temp->val);
//                 mp[temp]=nwnod;
//                 temp=temp->next;
//             }

//             temp=head;
//             while(temp!=NULL){
//                 Node* cpy=mp[temp];
//                 cpy->next=mp[temp->next];
//                 cpy->random=mp[temp->random];
//                 temp=temp->next;
//             }
//             return mp[head];
//         }
//     };

// a more optimal solution______________________________________________________________________

// 1st----> insert the copied node in-between
// 2nd----> connecting random pointers
// 3rd-----> connecting next pointers & extracting the required list

//tc=O(3n)         //sc=O(n)->cannot omit this , asked in quest(for ans only)



// class Solution
// {
// public:
//     Node *copyRandomList(Node *head)
//     {
//         Node *temp = head;

//         while (temp != NULL)     //O(N)
//         {
//             Node *cpynod = new Node(temp->val);
//             cpynod->next = temp->next;
//             temp->next = cpynod;
//             temp = temp->next->next;
//         }

//         temp = head;
//         while (temp != NULL)     //O(N)
//         {
//             Node *cpynod = temp->next;
//             if (temp->random == NULL)
//             {
//                 cpynod->random = NULL;
//             }
//             else
//                 cpynod->random = temp->random->next;
//             temp = temp->next->next;
//         }

//         temp = head;
//         Node *dummy = new Node(-1);
//         Node *res = dummy;
//         while (temp != NULL)     //O(N)
//         {
//             res->next = temp->next;
//             temp->next = temp->next->next;

//             res = res->next;
//             temp = temp->next;
//         }

//         return dummy->next;
//     }
// };