
// // Function to push an element into the queue.
// void MyQueue::push(int x)
// {
//     QueueNode *temp = new QueueNode(x);
//     if (front == NULL)
//     {
//         front = rear = temp;
//         return;
//     }
//     
//     rear->next = temp;
//     rear = temp;
//     return;
// }



// // Function to pop front element from the queue.
// int MyQueue ::pop()
// {

//     if (front == NULL)
//     {
//         return -1; // Queue is empty
//     }

//     int x = front->data;
//     QueueNode *temp = front; // Store the front node to free its memory
//     front = front->next;     // Move the front pointer to the next node

//     // If the queue becomes empty after the pop, set rear to NULL
//     if (front == NULL)
//     {
//         rear = NULL;
//     }

//     delete temp; // Free the memory of the old front node
//     return x;
// }