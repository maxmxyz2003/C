#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;
// Funciones para obtener la altura de un nodo y el máximo de dos números
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}
// Crear un nuevo nodo
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Nuevo nodo tiene altura 1
    return node;
}

// Rotación simple a la derecha
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realizar rotación
    x->right = y;
    y->left = T2;

    // Actualizar alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Retornar nueva raíz
    return x;
}

// Rotación simple a la izquierda
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realizar rotación
    y->left = x;
    x->right = T2;

    // Actualizar alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Retornar nueva raíz
    return y;
}

// Obtener el factor de balance del nodo
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Insertar un nodo en el árbol AVL
Node* insert(Node* node, int key) {
    // Realizar inserción de BST
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        // No permitir nodos duplicados
        return node;
    }

    // Actualizar altura de este nodo
    node->height = 1 + max(height(node->left), height(node->right));

    // Obtener el factor de balance de este nodo para verificar si se desbalanceó
    int balance = getBalance(node);

    // Caso izquierda-izquierda
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Caso derecha-derecha
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Caso izquierda-derecha
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso derecha-izquierda
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // El nodo está balanceado
    return node;
}

// Imprimir el árbol en orden
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->key);
    }
}
void preOrden(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrden(root->left);
        preOrden(root->right);
        
    }
}
// 18 33

int main() {
    Node* root = NULL;
    int values[] = {66, 51, 83, 94, 73, 78, 75, 81, 99, 77, 33, 74, 76, 55, 70, 18, 68};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Árbol AVL resultante en orden: ");
    inOrder(root);
    printf("\nÁrbol AVL resultante posorden: ");
    postOrderTraversal(root);
    printf("\nÁrbol AVL resultante preorden: ");
    preOrden(root);
    return 0;
}
