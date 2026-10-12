#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3

typedef struct Node {
    int numKeys;
    int keys[MAX_KEYS];
    struct Node* children[MAX_KEYS + 1];
    struct Node* parent;
} Node;
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->numKeys = 0;
    newNode->parent = NULL;
    for (int i = 0; i <= MAX_KEYS; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}
void splitNode(Node* parentNode, int insertIndex, int newKey) {
    Node* newRight = createNode();
    int midIndex = parentNode->numKeys / 2;
    int median = parentNode->keys[midIndex];
    for (int i = midIndex + 1, j = 0; i < parentNode->numKeys; ++i, ++j) {
        newRight->keys[j] = parentNode->keys[i];
        parentNode->keys[i] = 0;
        newRight->children[j] = parentNode->children[i];
        if (newRight->children[j]) {
            newRight->children[j]->parent = newRight;
        }
        parentNode->children[i] = NULL;
        newRight->numKeys++;
        parentNode->numKeys--;
    }
    newRight->children[newRight->numKeys] = parentNode->children[parentNode->numKeys];
    if (newRight->children[newRight->numKeys]) {
        newRight->children[newRight->numKeys]->parent = newRight;
    }
    parentNode->children[parentNode->numKeys] = NULL;
    parentNode->numKeys--;
    parentNode->keys[insertIndex] = median;
    if (parentNode->parent) {
        int parentInsertIndex = 0;
        while (parentInsertIndex < parentNode->parent->numKeys &&
               parentNode->parent->keys[parentInsertIndex] < median) {
            parentInsertIndex++;
        }

        for (int i = parentNode->parent->numKeys; i > parentInsertIndex; --i) {
            parentNode->parent->keys[i] = parentNode->parent->keys[i - 1];
            parentNode->parent->children[i + 1] = parentNode->parent->children[i];
        }

        parentNode->parent->keys[parentInsertIndex] = median;
        parentNode->parent->children[parentInsertIndex + 1] = newRight;
        newRight->parent = parentNode->parent;

        if (parentNode->parent->numKeys == MAX_KEYS) {
            splitNode(parentNode->parent, parentInsertIndex, median);
        }
    } else {
        // Create a new root
        Node* newRoot = createNode();
        newRoot->keys[0] = median;
        newRoot->children[0] = parentNode;
        newRoot->children[1] = newRight;
        parentNode->parent = newRoot;
        newRight->parent = newRoot;
        newRoot->numKeys = 1;
    }
}

void insert(Node* root, int newKey) {
    Node* currentNode = root;

    while (currentNode->children[0] != NULL) {
        int i = 0;
        while (i < currentNode->numKeys && newKey > currentNode->keys[i]) {
            i++;
        }
        currentNode = currentNode->children[i];
    }

    int insertIndex = 0;
    while (insertIndex < currentNode->numKeys && newKey > currentNode->keys[insertIndex]) {
        insertIndex++;
    }

    for (int i = currentNode->numKeys; i > insertIndex; --i) {
        currentNode->keys[i] = currentNode->keys[i - 1];
    }

    currentNode->keys[insertIndex] = newKey;
    currentNode->numKeys++;

    if (currentNode->numKeys == MAX_KEYS) {
        splitNode(currentNode, insertIndex, newKey);
    }
}

void printTree(Node* root) {
    if (root != NULL) {
        for (int i = 0; i < root->numKeys; ++i) {
            printTree(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        printTree(root->children[root->numKeys]);
    }
}

int main() {
    Node* root = createNode();
    int keys[] = {75, 30,10, 95, 11, 32, 39, 1, 7, 23,85,48,2,36,31,99,87,88};
    int numKeys = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < numKeys; ++i) {
        insert(root, keys[i]);
    }
    printf("B-tree after insertion: ");
    printTree(root);
    printf("\n");

    return 0;
}
