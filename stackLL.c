#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node_type;

void push(node_type **top, int x);
int pop(node_type **top);
void display(node_type *top);

int main() {
    node_type *top = NULL;
    int x, op;

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
                push(&top, x);
                break;
            case 2:
                x = pop(&top);
                if (x != -1) {
                    printf("\nPopped element: %d", x);
                }
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    } while (1);

    return 0;
}

void push(node_type **top, int x) {
    node_type *temp = (node_type *)malloc(sizeof(node_type));
    temp->data = x;
    temp->link = *top;
    *top = temp;
    printf("\nPushed element: %d", x);
}

int pop(node_type **top) {
    int x;
    if (*top == NULL) {
        printf("\nStack underflow!");
        return -1;
    } else {
        node_type *temp = *top;
        x = temp->data;
        *top = temp->link;
        free(temp);
        return x;
    }
}

void display(node_type *top) {
    if (top == NULL) {
        printf("\nStack is empty!");
    } else {
        printf("\nStack elements: ");
        while (top != NULL) {
            printf("%d ", top->data);
            top = top->link;
        }
    }
}