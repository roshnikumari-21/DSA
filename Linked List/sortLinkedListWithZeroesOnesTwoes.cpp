


// class Solution
// {
// public:
//     // Function to sort a linked list of 0s, 1s and 2s.
//     Node *segregate(Node *head)
//     {

//         Node *zh = new Node(-1);
//         Node *oh = new Node(-1);
//         Node *th = new Node(-1);

//         Node *zero = zh;
//         Node *one = oh;
//         Node *two = th;

//         Node *temp = head;
//         while (temp != NULL)
//         {
//             if (temp->data == 1)
//             {
//                 one->next = temp;
//                 one = temp;
//             }
//             else if (temp->data == 2)
//             {
//                 two->next = temp;
//                 two = temp;
//             }
//             else if (temp->data == 0)
//             {
//                 zero->next = temp;
//                 zero = temp;
//             }
//             temp = temp->next;
//         }


//         if (oh->next != NULL)
//         {
//             zero->next = oh->next;
//             one->next = th->next;
//         }

//         else
//         {
//             if (th->next != NULL)
//                 zero->next = th->next;
//         }
//         two->next = NULL;
//         return zh->next;
//     }
// };
