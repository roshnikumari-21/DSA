
// class MyStack
// {

// private:
//     StackNode *top;

// public:
//     void push(int x)
//     {
//         StackNode *temp = new StackNode(x);
//         if (top == NULL)
//         {
//             top = temp;
//             return;
//         }
//         temp->next = top;
//       
//         top = temp;
//         return;
//     }

//     int pop()
//     {
//         if (top == NULL)
//             return -1;
//         int x = top->data;
//         top = top->next;
//         return x;
//     }

//     MyStack() { top = NULL; }
// };
