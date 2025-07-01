// make tail pointing to head
// traverse to (n-k)th node
// update head
// make next point to null



//tc=O(2n)   sc=O(1)________________________


// int find(ListNode *head)
// {
//     int count = 0;
//     while (head != NULL)
//     {
//         count++;
//         head = head->next;
//     }
//     return count;
// }


// ListNode *rotateRight(ListNode *head, int k)
// {
//     if (head == NULL || head->next == NULL || k == 0)
//         return head;


//     int len = find(head);
//     k = k % len;
//     if (k == 0)
//         return head;
//     int len2 = len - k - 1;
//     ListNode *temp = head;
//     while (len2--)
//     {
//         temp = temp->next;
//     }
//     ListNode *nwhead = temp->next;
//     temp->next = NULL;
//     temp = nwhead;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = head;
//     return nwhead;
// }
// }
// ;
