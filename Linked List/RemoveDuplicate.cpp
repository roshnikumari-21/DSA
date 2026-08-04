//doubly linked list

//the duplicates will be in contiguous manner bcoz its sorted

//tc=O(N)




// Node* removeDuplicates(Node* head)
// {
//     Node* temp = head;

//     while (temp != NULL && temp->next != NULL) {
//         Node* nextNode = temp->next;

//         while (nextNode != NULL && nextNode->data == temp->data) {
//             Node* duplicate = nextNode;
//             nextNode = nextNode->next;
//             free(duplicate); // free memory of duplicate node
//         }

//         temp->next = nextNode;

//         if (nextNode != NULL)
//             nextNode->prev = temp;

//         temp = temp->next;
//     }

//     return head;
// }
