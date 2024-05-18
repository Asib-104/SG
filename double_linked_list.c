#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// Function to insert a node before a given node
void insertBefore(struct Node** head, struct Node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("Next node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        *head = newNode;
    }
    nextNode->prev = newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// Function to delete a node
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        return;
    }
    if (*head == delNode) {
        *head = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    free(delNode);
}

// Function to search for a node with a given key
struct Node* searchNode(struct Node* head, int key) {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

// Function to sort the linked list using bubble sort
void sortLinkedList(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    int swapped;
    struct Node* currentNode;
    struct Node* lastNode = NULL;
    do {
        swapped = 0;
        currentNode = *head;
        while (currentNode->next != lastNode) {
            if (currentNode->data > currentNode->next->data) {
                int temp = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = temp;
                swapped = 1;
            }
            currentNode = currentNode->next;
        }
        lastNode = currentNode;
    } while (swapped);
}

// Function to merge two linked lists
struct Node* mergeLinkedLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (head1->data < head2->data) {
        head1->next = mergeLinkedLists(head1->next, head2);
        head1->next->prev = head1;
        head1->prev = NULL;
        return head1;
    } else {
        head2->next = mergeLinkedLists(head1, head2->next);
        head2->next->prev = head2;
        head2->prev = NULL;
        return head2;
    }
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAfter(head->next, 15);
    insertBefore(&head, head->next->next, 25);

    // Display the linked list
    printf("Linked list: ");
    displayLinkedList(head);

    // Delete a node
    struct Node* delNode = searchNode(head, 20);
    deleteNode(&head, delNode);

    // Display the linked list after deletion
    printf("Linked list after deletion: ");
    displayLinkedList(head);

    // Sort the linked list
    sortLinkedList(&head);

    // Display the sorted linked list
    printf("Sorted linked list: ");
    displayLinkedList(head);

    // Create another linked list
    struct Node* head2 = NULL;
    insertAtEnd(&head2, 40);
    insertAtEnd(&head2, 50);
    insertAtEnd(&head2, 60);

    // Merge the two linked lists
    head = mergeLinkedLists(head, head2);

    // Display the merged linked list
    printf("Merged linked list: ");
    displayLinkedList(head);

    return 0;
}