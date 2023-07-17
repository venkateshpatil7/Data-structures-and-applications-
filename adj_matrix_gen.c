#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct TreeNode {
    int data;
    struct TreeNode* parent;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void generateAdjacencyMatrix(struct TreeNode* root, int matrix[MAX_NODES][MAX_NODES]) {
    if (root == NULL) return;

    if (root->left != NULL) {
        matrix[root->data - 1][root->left->data - 1] = 1;
        matrix[root->left->data - 1][root->data - 1] = 1;
        generateAdjacencyMatrix(root->left, matrix);
    }

    if (root->right != NULL) {
        matrix[root->data - 1][root->right->data - 1] = 1;
        matrix[root->right->data - 1][root->data - 1] = 1;
        generateAdjacencyMatrix(root->right, matrix);
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->parent = root;
    root->right->parent = root;

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;

    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->parent = root->right;
    root->right->right->parent = root->right;

    // Initialize the adjacency matrix
    int matrix[MAX_NODES][MAX_NODES] = {0};

    // Generate the adjacency matrix
    generateAdjacencyMatrix(root, matrix);

    // Print the adjacency matrix
    int n = 7; // Number of nodes in the tree
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
