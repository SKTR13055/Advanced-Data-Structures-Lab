#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node in the BST
struct Node {
    int data;               // Store the level of the character
    struct Node* left;      // Pointer to the left child (lower level)
    struct Node* right;     // Pointer to the right child (higher level)
};

// Function to create a new node with a given level
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;       // Set the character's level
    newNode->left = NULL;       // No lower level yet, so set left to NULL
    newNode->right = NULL;      // No higher level yet, so set right to NULL
    return newNode;
}

// Function to insert a new level in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, the new level becomes the root
        return createNode(data);
    }

    // If the new level is lower, insert it in the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If the new level is higher, insert it in the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Return the unchanged root pointer after insertion
    return root;
}

// Function to search for a specific level in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        // If the tree is empty or the level is found, return the node
        return root;
    }

    // If the level is lower than the current node, search in the left subtree
    if (key < root->data) {
        return search(root->left, key);
    }
    // Otherwise, search in the right subtree
    return search(root->right, key);
}

// Helper function to find the node with the minimum level in the BST (used in deletion)
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    // Traverse down to the leftmost leaf, which has the minimum level
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with a specific level from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;  // If the tree is empty, return NULL
    }

    // If the level to be deleted is lower, go to the left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // If the level to be deleted is higher, go to the right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // If the level matches the root's level, this is the node to delete
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;  // Get right child
            free(root);                       // Delete the current node
            return temp;                      // Return the right child as the new subtree root
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;   // Get left child
            free(root);                       // Delete the current node
            return temp;                      // Return the left child as the new subtree root
        }

        // Node with two children: Find the minimum value in the right subtree
        struct Node* temp = findMin(root->right);
        root->data = temp->data;              // Copy the minimum value to current node
        root->right = deleteNode(root->right, temp->data);  // Delete the duplicate node
    }
    return root;  // Return the updated root pointer
}

// Function to perform in-order traversal of the BST (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);              // Visit left subtree
        printf("%d ", root->data);        // Print current node's level
        inorder(root->right);             // Visit right subtree
    }
}

int main() {
    struct Node* root = NULL;         // Start with an empty BST

    // Insert values to form the BST
    root = insert(root, 50);  // Insert 50 as root
    insert(root, 30);         // Insert 30 to the left of 50
    insert(root, 20);         // Insert 20 to the left of 30
    insert(root, 40);         // Insert 40 to the right of 30
    insert(root, 70);         // Insert 70 to the right of 50
    insert(root, 60);         // Insert 60 to the left of 70
    insert(root, 80);         // Insert 80 to the right of 70

    // Print the BST in sorted order (in-order traversal)
    printf("Inorder traversal of the BST:\n");
    inorder(root);

    // Delete a node with level 20
    printf("\n\nDeleting 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting 20:\n");
    inorder(root);

    // Search for a node with level 60
    printf("\n\nSearching for 60:\n");
    struct Node* searchResult = search(root, 60);
    if (searchResult != NULL) {
        printf("Element found: %d\n", searchResult->data);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
