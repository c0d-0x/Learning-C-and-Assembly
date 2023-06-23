# Data Structures
## 1) Singly Linked List Implementation in C

This C code provides an implementation of a singly linked list along with various operations to manipulate the list. The program starts by defining a node structure that represents each element in the linked list. The main function demonstrates the usage of the implemented functions.

### Functions
print_list(node_t* L): This function prints the values of the linked list.

push(node_t* L, int value): This function adds a new node with the given value at the end of the linked list.

newNode(node_t** head, int value): This function adds a new node with the given value at the beginning of the linked list.

popHead(node_t** head): This function removes the first node from the linked list.

removeLast(node_t* headptr): This function removes the last node from the linked list.

removebyValue(node_t** headptr, int value): This function removes the first occurrence of a node with the given value from the linked list.

removeAllof(node_t** headptr, int value): This function removes all occurrences of nodes with the given value from the linked list.

### Usage
The main function initializes a linked list with a single node and demonstrates the usage of the implemented functions. It adds multiple nodes, removes specific nodes by value, and prints the final state of the linked list.

Please note that there is commented code for the function removeAllof that can be uncommented to enable the functionality of removing all occurrences of a given value in the linked list.

## 2) Stack Implementation using Array in C
This C code provides an implementation of a stack data structure using an array. The stack follows the Last-In-First-Out (LIFO) principle, where elements are added and removed from the top of the stack. The program starts by defining a constant MAX to represent the maximum size of the stack and declares an array stack to store the elements.

### Functions
isFull(): This function checks if the stack is full and returns 1 if it is, otherwise returns 0.

isEmpty(): This function checks if the stack is empty and returns 1 if it is, otherwise returns 0.

push(int value): This function adds an element with the given value to the top of the stack. If the stack is already full, it displays an error message and terminates the program.

displayStack(): This function prints the elements of the stack in reverse order to emphasize the Last-In-First-Out (LIFO) nature of the stack. If the stack is empty, it displays a message indicating that the stack is empty.

pop(): This function removes and returns the element from the top of the stack. If the stack is empty, it displays an error message and terminates the program.

peek(): This function returns the element at the top of the stack without removing it. If the stack is empty, it returns -1.

### Usage
The main function demonstrates the usage of the stack implementation. It pushes elements from 1 to MAX onto the stack, performs a pop operation, and then displays the current state of the stack using the displayStack function.

Please note that the maximum size of the stack is defined by the MAX constant. Feel free to modify and extend this code to suit your specific requirements.

## 3) Stack Implementation using Linked List in C
This C code provides an implementation of a stack data structure using a linked list. The stack follows the Last-In-First-Out (LIFO) principle, where elements are added and removed from the top of the stack. The program defines a structure stack to represent each element in the stack, which consists of an integer value and a pointer to the next node in the stack.

### Functions
isempty(stck **headptr): This function checks if the stack is empty by checking if the head pointer is NULL. It returns 1 if the stack is empty, otherwise returns 0.

pop(stck **headptr): This function removes and returns the element from the top of the stack. If the stack is empty, it displays an error message and terminates the program.

push(stck **headptr, int numb): This function adds an element with the given value to the top of the stack by creating a new node and updating the head pointer.

peek(stck *headptr): This function displays the value at the top of the stack without removing it. If the stack is empty, it does nothing.

stackinit(): This function initializes the stack by returning a NULL pointer.

### Usage
The main function demonstrates the usage of the stack implementation. It initializes the stack using the stackinit function, pushes elements from 1 to 10 onto the stack using the push function, performs a peek operation using the peek function, and finally performs a pop operation using the pop function and displays the popped value.

Please note that the stack is implemented using a linked list, and each node in the stack consists of 


### NB: Feel free to modify and extend this code to suit your specific requirements.




