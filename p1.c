#define Sz 5

#include <stdio.h>
#include <stdlib.h>

// Function to insert an element in the stack
void push(int S[Sz], int *top, int item) {
    if (*top == Sz - 1) {
        printf("Stack Overflow\n");
        return;
    }
    *top = *top + 1;
    S[*top] = item;
    printf("%d inserted into the stack\n", item);
}

// Function to delete an element from the stack
void pop(int S[Sz], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d is deleted\n", S[*top]);
    *top = *top - 1;
}

// Function to display the stack contents
void display(int S[Sz], int top) {
    int i;
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Content of Stack:\n");
    for (i = 0; i <= top; i++) {
        printf("%d\n", S[i]);
    }
}

// Function to check for palindrome
void palindrome(int S[Sz], int top) {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    int rev[Sz], len = top + 1;
    int i, isPalindrome = 1;

    // Reverse the array
    for (i = 0; i < len; i++) {
        rev[i] = S[top - i];
    }

    // Display the original and reversed array
    printf("Array elements are:\n");
    for (i = 0; i < len; i++) {
        printf("%d\t", S[i]);
    }
    printf("\nReverse array:\n");
    for (i = 0; i < len; i++) {
        printf("%d\t", rev[i]);
    }

    // Check for palindrome
    for (i = 0; i < len; i++) {
        if (S[i] != rev[i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("\nIt is a palindrome number\n");
    } else {
        printf("\nIt is not a palindrome number\n");
    }
}

// Main function
int main() {
    int S[Sz], top = -1, item, ch;

    for (;;) {
        printf("1: Insert 2: Delete 3: Display 4: Palindrome 5: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the item:\n");
                scanf("%d", &item);
                push(S, &top, item);
                break;

            case 2:
                pop(S, &top);
                break;

            case 3:
                display(S, top);
                break;

            case 4:
                palindrome(S, top);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice, Please try again\n");
        }
    }

    return 0;
}






























