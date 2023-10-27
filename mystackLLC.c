#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *top = NULL, *ptr;

void push(int ele){
    Node *new = (Node *)malloc(sizeof( Node ));

    if (new == NULL){
        printf("Underflow, space not allocated\n");
    }
    else{
        new->data = ele;
        new->next = top;
        top = new;
    }
}

void pop(){
    if (top == NULL){
        printf("Underflow, no elements present in the stack\n");
    }
    else{
        ptr = top;
        printf("Deleted the element %d",ptr->data);
        top = ptr->next;
        ptr->next = NULL;
        free(ptr);
    }
}

void display(){
    if (top == NULL){
        printf("Underflow, no elements available to display\n");
    }
    else{
        ptr = top;
        while (ptr != NULL){
            printf("%d->",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int ele,cho;
    do{
        printf("//***Menu Section***//\n");
        printf("Press 1 to push\n");
        printf("Press 2 to pop\n");
        printf("Press 3 to display\n");
        printf("Press 4 to exit\n");
        printf("_________________________\n");
        printf("Enter your choice\n");
        scanf("%d",&cho);

        switch (cho){
            case 1:
                printf("Enter the element to enter\n");
                scanf("%d",&ele);
                push(ele);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }while(1);
}
