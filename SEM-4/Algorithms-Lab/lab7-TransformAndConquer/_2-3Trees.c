//To implement 2-3 trees
//Input - keys
//Output - 2-3 tree representation
//Time complexity - O(log n)

#include <stdio.h>
#include <stdlib.h>

// Node structure for 2-3 tree
struct Node {
    int data[2];
    struct Node *child[3];
    int numKeys;
};

// Function to create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data[0] = key;
    newNode->data[1] = -1;
    newNode->child[0] = NULL;
    newNode->child[1] = NULL;
    newNode->child[2] = NULL;
    newNode->numKeys = 1;
    return newNode;
}

// Function to split a node
void splitNode(struct Node *parent, int index) {
    struct Node *newNode = createNode(parent->data[1]);

    if (index == 0) {
        newNode->child[0] = parent->child[1];
        newNode->child[1] = parent->child[2];
        parent->child[1] = NULL;
        parent->child[2] = NULL;
    } else if (index == 1) {
        newNode->child[0] = parent->child[2];
        parent->child[2] = NULL;
    }

    parent->data[1] = -1;
    parent->numKeys = 1;
    newNode->numKeys = 1;

    if (parent->child[index + 1] != NULL)
        parent->child[index + 1] = newNode;
    else
        parent->child[2] = newNode;
}

// Function to insert a key into the tree
void insert(struct Node **root, int key) {
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    struct Node *current = *root;
    struct Node *parent = NULL;
    int index;

    while (current != NULL) {
        if (current->numKeys == 2) {
            if (parent == NULL) {
                *root = createNode(current->data[1]);
                (*root)->child[0] = current;
                parent = *root;
            } else {
                index = (parent->child[0] == current) ? 0 : 1;
                splitNode(parent, index);
            }
        }

        if (key < current->data[0]) {
            parent = current;
            current = current->child[0];
            index = 0;
        } else if (key > current->data[current->numKeys - 1]) {
            parent = current;
            current = current->child[2];
            index = 2;
        } else {
            parent = current;
            current = current->child[1];
            index = 1;
        }
    }

    parent->data[parent->numKeys] = key;
    parent->numKeys++;
}

// Function to search for a key in the tree
int search(struct Node *root, int key) {
    if (root == NULL)
        return 0;

    if (root->data[0] == key || (root->numKeys == 2 && root->data[1] == key))
        return 1;
    else if (key < root->data[0])
        return search(root->child[0], key);
    else if (root->numKeys == 1 || (root->numKeys == 2 && key < root->data[1]))
        return search(root->child[1], key);
    else
        return search(root->child[2], key);
}

// Function to perform an inorder traversal of the tree
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->child[0]);
        printf("%d ", root->data[0]);
        if (root->numKeys == 2)
            printf("%d ", root->data[1]);
        inorderTraversal(root->child[1]);
        if (root->numKeys == 2)
            inorderTraversal(root->child[2]);
    }
}

int main() {
    struct Node *root = NULL;

    // Insert elements into the tree
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);

    // Inorder traversal to display the elements in sorted order
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for an element in the tree
    int keyToSearch = 12;
    if (search(root, keyToSearch))
        printf("%d is found in the tree.\n", keyToSearch);
    else
        printf("%d is not found in the tree.\n", keyToSearch);

    return 0;
}
