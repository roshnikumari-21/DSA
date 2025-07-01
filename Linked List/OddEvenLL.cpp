
// class Solution {
//     public:
//         ListNode* oddEvenList(ListNode* head) {
//             if(head==NULL) return head;
//             ListNode* head1=head;
//             ListNode* head2=head->next;
//             ListNode* temp=head2;
//             while(head1!=NULL && head1->next!=NULL && head2!=NULL && head2->next!=NULL){
//                 head1->next=head2->next;
//                 head1=head1->next;
//                 head2->next=head1->next;
//                 head2=head2->next;
//             }
//             head1->next=temp;
//             return head;
//         }
//     };