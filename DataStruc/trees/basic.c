#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura del nodo del árbol
struct TreeNodeCalc {
    int data;
    struct TreeNodeCalc* left;
    struct TreeNodeCalc* right;
};

struct TreeNodeN{
    char *name;
    struct TreeNodeN* left;
    struct TreeNodeN* right;
};

typedef struct ArNode {
    int dato;
    struct ArNode* izq;
    struct ArNode* der;
} * AB;
// Función para crear un nuevo nodo
struct TreeNodeCalc* createNode(int value) {
    struct TreeNodeCalc* newNode = (struct TreeNodeCalc*)malloc(sizeof(struct TreeNodeCalc));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Función para agregar un nodo al árbol binario
struct TreeNodeCalc* insertNode(struct TreeNodeCalc* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}
// Recorrido en orden (in-order)
void inOrderTraversal(struct TreeNodeCalc* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
// Same structure
int SameStruct(struct TreeNodeCalc* root1, struct TreeNodeCalc* root2){
    if(!root1&&!root2){
        return 1;
    }else if(!root1||!root2){
        return 0;
    }else{
        return SameStruct(root1->left, root2->left)*SameStruct(root1->right, root2->right);
    }
}
//Height
int CalcHeight(struct TreeNodeCalc* root){
    if (!root){
        return 0;
    }else{
        int LH=CalcHeight(root->left);
        int RH=CalcHeight(root->right);
        return LH>RH?LH+1:RH+1;
    }
}
//Duped data XD
int DuppedData(struct TreeNodeCalc* root, int data){
    int reps=0;
    if (!root){
        return 0;
    }else{
        if (root->data==data)
            reps++;
        return reps+DuppedData(root->left,data)+DuppedData(root->left,data);
    }
}
//Print "daughters"
void printLeftNodes(struct TreeNodeCalc* root) {
    if (root){
        if (root->left) {
            printf("%d ", root->left->data);
        }
        printLeftNodes(root->left);
        printLeftNodes(root->right);
    }
}
void printLeftNodesChar(struct TreeNodeN* root) {
    if (root){
        if (root->left) {
            printf("%s ", root->left->name);
        }
        printLeftNodes(root->left);
        printLeftNodes(root->right);
    }
}


// Recorrido preorden
void preOrderTraversal(struct TreeNodeCalc* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
// Recorrido postorden
void postOrderTraversal(struct TreeNodeCalc* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Función principal
int main() {
    struct TreeNodeCalc* root = NULL;
    struct TreeNodeCalc* root2 = NULL;
    // Agregar nodos al árbol
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    root2 = insertNode(root2, 50);
    insertNode(root2, 30);
    insertNode(root2, 20);
    insertNode(root2, 40);
    insertNode(root2, 70);
    insertNode(root2, 60);
    insertNode(root2, 80);

    struct TreeNodeCalc* root3 =NULL;
    root3 = insertNode(root3, 50);
    insertNode(root3, 40);
    insertNode(root3, 70);
    insertNode(root3, 40);
    insertNode(root3, 80);
    insertNode(root3, 40);
    insertNode(root3, 60);
    insertNode(root3, 40);

    printLeftNodes(root2);
    printf("\n");
    if (DuppedData(root3, 40))
    {
        printf("%d times 40\n", DuppedData(root3, 40));
    }
    printf("-------\n");
    printf("H: %d \n",CalcHeight(root2));
    printf("-------\n");
    if (SameStruct(root,root2))
    {printf("YAY\n");
    }else{printf("NON\n");}
    // Realizar recorridos
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");
    printf("Post-order traversal: ");
    postOrderTraversal(root);
    return 0;
}
