// Node* removesHead(Node* head) {
//     if (head == NULL) return head;
//     Node* temp = head;
//     head = head->next;
//     delete temp;
//     return head;
// }

//delete tail______________________________________


// Node* removeTail(Node* head) {
//     if (head == NULL || head->next == NULL) return NULL;

//     Node* temp = head;
//     while (temp->next->next != NULL) {
//         temp = temp->next;
//     }

//     delete temp->next;
//     temp->next = nullptr;

//     return head;
// }


//remove kth node from start____________________________________

// Node* removeK(Node* head, int k) {
//     if (head == NULL) return head;

//     if (k == 1) {
//         Node* temp = head;
//         head = head->next;
//         free(temp);
//         return head;
//     }

//     int cnt = 0;
//     Node* temp = head;
//     Node* prev = NULL;
//     while (temp != NULL) {
//         cnt++;
//         if (cnt == k) {
//             prev->next = prev->next->next;
//             free(temp);
//             break;
//         }
//         prev = temp;
//         temp = temp->next;
//     }

//     return head;
// }



//insertion at headd____________________


// Node* insertHead(Node* head, int val) {
//     Node* temp = new Node(val);
//     temp->next = head;
//     return temp;
// }



//insert at tail_________________________


// Node* insertTail(Node* head, int val) {
//     if (head == NULL) {
//         return new Node(val);
//     }

//     Node* temp = head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }

//     Node* newNode = new Node(val);
//     temp->next = newNode;

//     return head;
// }


//insert at first position______________________________________________



// Node* insertPosition(Node* head, int el, int k) {
//     if (head == NULL) {
//         if (k == 1) {
//             return new Node(el);
//         } else {
//             return head;
//         }
//     }

//     if (k == 1) {
//         return new Node(el, head);
//     }

//     int cnt = 0;
//     Node* temp = head;
//     while (temp != NULL) {
//         cnt++;
//         if (cnt == (k - 1)) {
//             Node* x = new Node(el, temp->next);
//             temp->next = x;
//             break;
//         }
//         temp = temp->next;
//     }

//     return head;
// }


//insert before value x________________________________________________________


// Node* insertBeforeValue(Node* head, int el, int val) {
//     if (head == NULL) {
//         return NULL;
//     }

//     if (head->data == val) {
//         return new Node(el, head);
//     }

//     Node* temp = head;
//     while (temp->next != NULL) {
//         if (temp->next->data == val) {
//             Node* x = new Node(el, temp->next);
//             temp->next = x;
//             break;
//         }
//         temp = temp->next;
//     }

//     return head;
// }

//array are stored at contiguous location
//ll not contingous

//length of linked list_______________________________________

// int getLength(Node* head) {
//     int length = 0;
//     Node* temp = head;

//     while (temp != NULL) {
//         length++;
//         temp = temp->next;
//     }

//     return length;
// }



//to search a node in ll___________________________________________


// bool searchNode(Node* head, int key) {
//     Node* temp = head;

//     while (temp != NULL) {
//         if (temp->data == key)
//             return true;  // Key found
//         temp = temp->next;
//     }

//     return false;  // Key not found
// }
