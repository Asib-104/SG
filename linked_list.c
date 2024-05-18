#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node after a given node
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a new node before a given node
void insertBefore(struct Node** headRef, struct Node* nextNode, int newData) {
    if (nextNode == NULL) {
        printf("Next node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = nextNode;

    if (*headRef == nextNode) {
        *headRef = newNode;
    } else {
        struct Node* currentNode = *headRef;
        while (currentNode->next != nextNode) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Function to insert a new node at a given position
void insertAtPosition(struct Node** headRef, int position, int newData) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newData;
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    struct Node* currentNode = *headRef;
    for (int i = 1; i < position - 1 && currentNode != NULL; i++) {
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

// Function to delete a node after a given node
void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("No node to delete.\n");
        return;
    }

    struct Node* nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to delete a node before a given node
void deleteBefore(struct Node** headRef, struct Node* nextNode) {
    if (*headRef == NULL || nextNode == NULL || *headRef == nextNode) {
        printf("No node to delete.\n");
        return;
    }

    if ((*headRef)->next == nextNode) {
        struct Node* nodeToDelete = *headRef;
        *headRef = nextNode;
        free(nodeToDelete);
        return;
    }

    struct Node* currentNode = *headRef;
    while (currentNode->next != nextNode && currentNode->next->next != nextNode) {
        currentNode = currentNode->next;
    }

    if (currentNode->next != nextNode) {
        printf("No node to delete.\n");
        return;
    }

    struct Node* nodeToDelete = currentNode->next;
    currentNode->next = nextNode;
    free(nodeToDelete);
}

// Function to delete a node at a given position
void deleteAtPosition(struct Node** headRef, int position) {
    if (*headRef == NULL || position < 1) {
        printf("No node to delete.\n");
        return;
    }

    if (position == 1) {
        struct Node* nodeToDelete = *headRef;
        *headRef = (*headRef)->next;
        free(nodeToDelete);
        return;
    }

    struct Node* currentNode = *headRef;
    for (int i = 1; i < position - 1 && currentNode != NULL; i++) {
        currentNode = currentNode->next;
    }

    if (currentNode == NULL || currentNode->next == NULL) {
        printf("No node to delete.\n");
        return;
    }

    struct Node* nodeToDelete = currentNode->next;
    currentNode->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to sort the linked list using bubble sort
void sortLinkedList(struct Node** headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) {
        return;
    }

    int swapped;
    struct Node* currentNode;
    struct Node* lastNode = NULL;

    do {
        swapped = 0;
        currentNode = *headRef;

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

// Function to merge two sorted linked lists
struct Node* mergeLinkedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* mergedList = NULL;

    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeLinkedLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLinkedLists(list1, list2->next);
    }

    return mergedList;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        struct Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAfter(head, 1);
    insertAfter(head, 3);
    insertAfter(head, 5);
    insertBefore(&head, head, 0);
    insertBefore(&head, head->next, 2);
    insertBefore(&head, head->next->next, 4);
    insertAtPosition(&head, 7, 6);

    // Print the linked list
    printf("Linked list: ");
    printLinkedList(head);

    // Delete nodes
    deleteAfter(head);
    deleteBefore(&head, head->next->next);
    deleteAtPosition(&head, 4);

    // Print the modified linked list
    printf("Modified linked list: ");
    printLinkedList(head);

    // Sort the linked list
    sortLinkedList(&head);
    printf("Sorted linked list: ");
    printLinkedList(head);

    // Merge two linked lists
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertAfter(list1, 1);
    insertAfter(list1, 3);
    insertAfter(list1, 5);

    insertAfter(list2, 2);
    insertAfter(list2, 4);
    insertAfter(list2, 6);

    struct Node* mergedList = mergeLinkedLists(list1, list2);
    printf("Merged linked list: ");
    printLinkedList(mergedList);

    // Free the memory allocated for the linked lists
    freeLinkedList(head);
    freeLinkedList(mergedList);

    return 0;
}