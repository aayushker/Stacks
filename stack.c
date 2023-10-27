#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct stack {
    int eit[size];
    int top;
} stack_type;

void init(stack_type *a);
int underflow(stack_type *a);
int overflow(stack_type *a);
void push(stack_type *a, int x);
int pop(stack_type *a);
void display(stack_type *a);

int main() {
    stack_type a;
    int x, op;
    init(&a);

    do {
        printf("\n\nMENU");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nEnter element to push: ");
                scanf("%d", &x);
                push(&a, x);
                break;
            case 2:
                x = pop(&a);
                if (x != -1) {
                    printf("\nPopped element: %d", x);
                }
                break;
            case 3:
                display(&a);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    } while (1);

    return 0;
}

void init(stack_type *a) {
    a->top = -1;
}

int underflow(stack_type *a) {
    if (a->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int overflow(stack_type *a) {
    if (a->top == size - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(stack_type *a, int x) {
    if (overflow(a)) {
        printf("\nStack overflow!");
    } else {
        a->top++;
        a->eit[a->top] = x;
        printf("\nPushed element: %d", x);
    }
}

int pop(stack_type *a) {
    int x;
    if (underflow(a)) {
        printf("\nStack underflow!");
        return -1;
    } else {
        x = a->eit[a->top];
        a->top--;
        return x;
    }
}

void display(stack_type *a) {
    if (underflow(a)) {
        printf("\nStack is empty!");
    } else {
        printf("\nStack elements: ");
        for (int i = a->top; i >= 0; i--) {
            printf("%d ", a->eit[i]);
        }
    }
}