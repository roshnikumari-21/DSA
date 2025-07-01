

// take carry=0  and start iterating...if at any point carry==1----> break


//brute--->revesse the ll, traverses and add, again reverse, iterative
//tc=O(3N) sc=O(1)


//recursive___________tc=O(N)_______sc=O(1)

// int addHelper(Node* temp) {
//     if (temp == NULL) {       //base case
//         return 1; 
//     }

//     int carry = addHelper(temp->next); // Recurse to the end
//     temp->data += carry;               // Add carry to current node
    
//     if (temp->data < 10) return 0;     // No further carry needed
//     temp->data = 0;                    // Reset to 0 and return carry
//     return 1;
// }


// Node* addOne(Node* head) {
//     int carry = addHelper(head);

//     if (carry == 1) {
//         Node* newNode = new Node(1); // New head with 1
//         newNode->next = head;        // Point to old head
//         head = newNode;              // Update head
//     }

//     return head;
// }
