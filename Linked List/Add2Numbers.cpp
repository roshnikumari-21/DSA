// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

//tc=O(n+m)


// class Solution {
//     public:
//         ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//             if(l1==NULL && l2==NULL) return NULL;
    
//             int carr=0;
//             ListNode* dum=new ListNode(-1);
//             ListNode* temp=dum;
//             while(l1!=NULL && l2!=NULL){
//                 int sum=(l1->val)+(l2->val)+carr;
//                 int value=sum%10;
//                 ListNode* nod=new ListNode(value);
//                 temp->next=nod;
//                 temp=temp->next;
//                 carr=sum/10;
//                 l1=l1->next;
//                 l2=l2->next;
    
//             }
//             while(l1!=NULL){
//                  int sum=l1->val+carr;
//                 int value=sum%10;
//                 ListNode* nod=new ListNode(value);
//                 temp->next=nod;
//                  temp=temp->next;
//                 carr=sum/10;
               
//                 l1=l1->next;        
//             }
    
//              while(l2!=NULL){
//                  int sum=l2->val+carr;
//                 int value=sum%10;
//                 ListNode* nod=new ListNode(value);
//                 temp->next=nod;
//                  temp=temp->next;
//                 carr=sum/10;
//                 l2=l2->next;        
//             }

//             if(carr>0) {
//                  ListNode* nod=new ListNode(carr);
//                  temp->next=nod;
//             }
//                    return dum->next;
    
//         }
//     };