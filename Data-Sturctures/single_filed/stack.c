#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

// checks if the stack is full
int isFull(void) {
  if (top == MAX - 1)
    return 1;
  else
    return 0;
  ;
}

// checks if the stack is empty
int isEmpty(void) {
  if (top == -1)
    return 1;
  else
    return 0;
}

int push(int value) {
  if (isFull()) {
    printf("Error(overflow): The stack is full!!!\n");
    exit(1);
  } else {
    top++;
    stack[top] = value;
    return 0;
  }
}

// Print the stack in reverse to emphasize the 'LIFO' rule.
void displayStack(void) {
  if (isEmpty()) {
    printf("stack is empty\n");
  } else {
    for (int i = top; i >= 0; i--) {
      printf("%d \n", stack[i]);
    }
  }
}

int pop(void) {
  if (!isEmpty()) {
    top--;
    return stack[top];
    ;
  } else {
    printf("Stack is Empty");
    exit(1);
  }
}

// having a peek on top of the Stack
int peek(void) {
  if (!isEmpty())
    return stack[top];
  return -1;
}

int main(void) {

  for (int i = 0; i < MAX; i++) {
    push(i + 1);
  }
  pop();
  displayStack();
  return 0;
}
