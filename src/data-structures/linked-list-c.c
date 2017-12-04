#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

int myNode = 20;

struct node* linkedList() {
    struct node *newNode, *tmp;

    // allocate memory for a new node
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return head;
}

void push_back(struct node *head, int value) {

}

void delete_list(struct node *head) {
    node *tmp = head;
    node *next = head;

    if (tmp != NULL) {
        while (tmp != NULL) {
            next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }
}

void display() {
    node *tmp = head;
    node *next = head;

    if (head != NULL) {
        while (tmp != NULL) {
            printf("%d\t", tmp->data);
        }
    } else {
        printf("\n\n the list is empty");
    }
}
