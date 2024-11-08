#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node *head=NULL;

struct node* create(struct node* head) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter a node value: ");
    scanf("%d",&newNode->value);
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    } else {
        struct node *ptr = head;
        while(ptr->next!=NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}

struct node* insert(struct node* p) {
    struct node* newNode1;
    newNode1 = (struct node*)malloc(sizeof(struct node));
    printf("Enter a node value: ");
    scanf("%d", &newNode1->value);
    newNode1->next=NULL;
    printf("1. Insert as head\n2. Inser as After\n");
    int ch, x;
    printf("Enter your choice: ");
    scanf("%d",&ch);
    if(ch == 1) {
        newNode1->next = p;
        p = newNode1;
    } else if(ch == 2) {
        printf("Enter the value after whch you want to inser: ");
        scanf("%d",&x);
        struct node* current = p;
        while(current!=NULL && current->value!=x) {
            current  = current->next;
        }
        if(current!=NULL) {
            newNode1->next = current->next;
            current->next = newNode1;
        } else {
            printf("Node value not found");
            free(newNode1);
        }
    } else {
        printf("Invalid Choice\n");
        free(newNode1);
    }
    return p;
}

void display(struct node* p) {
    if(p == NULL) {
        printf("The list is empty\n");
        return;
    }
    while(p!=NULL) {
        printf("%d -> ",p->value);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    int ch;
    while(1) {
        printf("1. Create\n2. Display\n3. Insert\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch == 1){
            head = create(head);
        } else if(ch == 2) {
            display(head);
        } else if(ch == 3) {
            head = insert(head);
        } else {
            break;
        }
    }
    return 0;
}
