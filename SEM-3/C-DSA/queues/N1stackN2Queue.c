/*Design a data representation, sequentially mapping n data objects into an array
A(1:m). n1 of these data objects are stacks and the remaining n2 = n - n1 are queues.
Write algorithms to add and delete elements from these data structures. Use the same 
SPACE_FULL algorithm for both types of data structures. This algorithm should 
provide space for the i-th data object if there is some space not currently being used. 
Note that a circular queue with space for r elements can hold only r – 1 elements.
Illustrate the working by writing a c program*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Data structure to represent a stack or a queue
typedef struct {
    int type; // 0 for stack, 1 for queue
    int front;
    int rear;
    int size;
} DataObject;

DataObject dataObjects[MAX_SIZE]; // Array to store information about data objects
int A[MAX_SIZE]; // Array for storing elements

void initializeDataObjects(int n1, int n2) {
    int i;
    for (i = 0; i < n1; i++) {
        dataObjects[i].type = 0; // Stack
        dataObjects[i].front = dataObjects[i].rear = -1;
        dataObjects[i].size = 0;
    }
    for (; i < n1 + n2; i++) {
        dataObjects[i].type = 1; // Queue
        dataObjects[i].front = dataObjects[i].rear = -1;
        dataObjects[i].size = 0;
    }
}

int SPACE_FULL(int i, int m) {
    return (dataObjects[i].size == m - 1);
}

// Implement push and pop operations for stacks
void push(int i, int element, int m) {
    if (!SPACE_FULL(i, m)) {
        dataObjects[i].rear = (dataObjects[i].rear + 1) % m;
        A[dataObjects[i].rear] = element;
        dataObjects[i].size++;
    } else {
        printf("Stack %d is full. Cannot push.\n", i);
    }
}

int pop(int i, int m) {
    if (dataObjects[i].size > 0) {
        int element = A[dataObjects[i].rear];
        dataObjects[i].rear = (dataObjects[i].rear - 1 + m) % m;
        dataObjects[i].size--;
        return element;
    } else {
        printf("Stack %d is empty. Cannot pop.\n", i);
        return -1; // Return -1 to indicate an empty stack
    }
}

// Implement enqueue and dequeue operations for queues
void enqueue(int i, int element, int m) {
    if (!SPACE_FULL(i, m)) {
        if (dataObjects[i].size == 0) {
            dataObjects[i].front = dataObjects[i].rear = 0;
        } else {
            dataObjects[i].rear = (dataObjects[i].rear + 1) % m;
        }
        A[dataObjects[i].rear] = element;
        dataObjects[i].size++;
    } else {
        printf("Queue %d is full. Cannot enqueue.\n", i);
    }
}

int dequeue(int i, int m) {
    if (dataObjects[i].size > 0) {
        int element = A[dataObjects[i].front];
        if (dataObjects[i].size == 1) {
            dataObjects[i].front = dataObjects[i].rear = -1;
        } else {
            dataObjects[i].front = (dataObjects[i].front + 1) % m;
        }
        dataObjects[i].size--;
        return element;
    } else {
        printf("Queue %d is empty. Cannot dequeue.\n", i);
        return -1; // Return -1 to indicate an empty queue
    }
}

int main() {
    int n1, n2, m;
    printf("Enter the number of stacks (n1): ");
    scanf("%d", &n1);
    printf("Enter the number of queues (n2): ");
    scanf("%d", &n2);
    m = n1 + n2; // Total size of the array

    initializeDataObjects(n1, n2);

    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int stackNum, element;
            printf("Enter stack number: ");
            scanf("%d", &stackNum);
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(stackNum, element, m);
        } else if (choice == 2) {
            int stackNum = 0; // Stack number
            if (n1 > 1) {
                printf("Enter stack number: ");
                scanf("%d", &stackNum);
            }
            int element = pop(stackNum, m);
            if (element != -1) {
                printf("Popped element: %d\n", element);
            }
        } else if (choice == 3) {
            int queueNum, element;
            printf("Enter queue number: ");
            scanf("%d", &queueNum);
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(queueNum + n1, element, m);
        } else if (choice == 4) {
            int queueNum = 0; // Queue number
            if (n2 > 1) {
                printf("Enter queue number: ");
                scanf("%d", &queueNum);
            }
            int element = dequeue(queueNum + n1, m);
            if (element != -1) {
                printf("Dequeued element: %d\n", element);
            }
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
