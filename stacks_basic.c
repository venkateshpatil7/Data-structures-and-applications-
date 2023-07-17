#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

/* Function to check if stack is empty */
int isEmpty()
{
    return (top == -1);
}

/* Function to check if stack is full */
int isFull()
{
    return (top == MAX_SIZE - 1);
}

/* Function to push an element onto the stack */
void push(int value)
{
    if (isFull()) {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = value;
}

/* Function to pop an element from the stack */
int pop()
{
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

/* Function to display the contents of the stack */
void display()
{
    int i;
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents:\n");
    for ( i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int num, value,i;
    srand(time(NULL)); // Seed the random number generator

    printf("How many numbers do you want to generate?\n");
    scanf("%d", &num);

    for ( i = 0; i < num; i++) {
        value = rand() % 100; // Generate a random number between 0 and 99
        printf("Pushing %d onto the stack.\n", value);
        push(value);
    }

    display();

    int choice;
    do {
        printf("Choose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push onto the stack:\n");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
