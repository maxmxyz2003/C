#include <stdio.h>
#include <stdlib.h>
// Define the structure for a tree node
struct TreeNodeCalc {
    char operator; // For operators like '+', '-', '*', '/'
    int value;     // For numeric values
    struct TreeNodeCalc* left;
    struct TreeNodeCalc* right;
};
// Function to create a new tree node for an operator
struct TreeNodeCalc* createOperatorNode(char op, struct TreeNodeCalc* left, struct TreeNodeCalc* right) {
    struct TreeNodeCalc* newNode = (struct TreeNodeCalc*)malloc(sizeof(struct TreeNodeCalc));
    newNode->operator = op;
    newNode->value = 0; // Not used for operators
    newNode->left = left;
    newNode->right = right;
    return newNode;
}
// Function to create a new tree node for a numeric value
struct TreeNodeCalc* createValueNode(int value) {
    struct TreeNodeCalc* newNode = (struct TreeNodeCalc*)malloc(sizeof(struct TreeNodeCalc));
    newNode->operator = '\0'; // Not used for values
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to evaluate the expression tree
int evaluateTree(struct TreeNodeCalc* root) {
    if (root) {
        if (root->operator == '\0') {
            return root->value;
        } else {
            int leftResult = evaluateTree(root->left);
            int rightResult = evaluateTree(root->right);
            switch (root->operator) {
                case '+':
                    return leftResult + rightResult;
                case '-':
                    return leftResult - rightResult;
                case '*':
                    return leftResult * rightResult;
                case '/':
                    // Check for division by zero
                    if (rightResult != 0) {
                        return leftResult / rightResult;
                    } else {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                default:
                    printf("Error: Unknown operator\n");
                    exit(EXIT_FAILURE);
            }
        }
    }else    
        return 0;
}
int main() {
    // Build a simple expression tree for (3 + 4) * 2
    struct TreeNodeCalc* root = createOperatorNode('*', createOperatorNode('+', createValueNode(3), createValueNode(4)), createValueNode(2));
    // Evaluate and print the result
    int result = evaluateTree(root);
    printf("Result: %d\n", result);
    // Clean up: free allocated memory
    // Note: A complete cleanup function may need to recursively free all nodes in the tree
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}
