#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform pre-order traversal and write to file
void preorder(struct Node* root, FILE* fp) {
    if (root != NULL) {
        fprintf(fp, "%d ", root->data);
        preorder(root->left, fp);
        preorder(root->right, fp);
    }
}

// Function to perform in-order traversal and write to file
void inorder(struct Node* root, FILE* fp) {
    if (root != NULL) {
        inorder(root->left, fp);
        fprintf(fp, "%d ", root->data);
        inorder(root->right, fp);
    }
}

// Function to perform post-order traversal and write to file
void postorder(struct Node* root, FILE* fp) {
    if (root != NULL) {
        postorder(root->left, fp);
        postorder(root->right, fp);
        fprintf(fp, "%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;

    // Generate random numbers and insert into BST
    int i;
    for (i = 0; i < 10; i++) {
        int randomNumber = rand() % 100; // Generate a random number between 0 and 99
        root = insert(root, randomNumber);
    }

    // Open files for writing
    FILE* preOrderFile = fopen("preorder.txt", "w");
    FILE* inOrderFile = fopen("inorder.txt", "w");
    FILE* postOrderFile = fopen("postorder.txt", "w");

    // Perform traversals and write to files
    preorder(root, preOrderFile);
    inorder(root, inOrderFile);
    postorder(root, postOrderFile);

    // Close files
    fclose(preOrderFile);
    fclose(inOrderFile);
    fclose(postOrderFile);

    return 0;
}
