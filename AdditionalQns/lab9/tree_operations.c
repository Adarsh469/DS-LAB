#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* createTree() {
    int value;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);
    if (value == -1)
        return NULL;
    Node* root = createNode(value);
    printf("Enter left child of %d:\n", value);
    root->left = createTree();
    printf("Enter right child of %d:\n", value);
    root->right = createTree();
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int areEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) &&
           areEqual(root1->left, root2->left) &&
           areEqual(root1->right, root2->right);
}

int areMirror(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) &&
           areMirror(root1->left, root2->right) &&
           areMirror(root1->right, root2->left);
}

Node* copyTree(Node* root) {
    if (root == NULL)
        return NULL;
    Node* newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

int main() {
    Node *root1 = NULL, *root2 = NULL, *copy = NULL;
    int choice;

    while (1) {
        printf("\n===== Binary Tree Operations =====\n");
        printf("1. Create Tree 1\n");
        printf("2. Create Tree 2\n");
        printf("3. Check if Tree 1 and Tree 2 are Equal\n");
        printf("4. Check if Tree 1 and Tree 2 are Mirror Images\n");
        printf("5. Copy Tree 1 into a New Tree\n");
        printf("6. Display Trees (Inorder Traversal)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating Tree 1...\n");
                root1 = createTree();
                break;
            case 2:
                printf("Creating Tree 2...\n");
                root2 = createTree();
                break;
            case 3:
                if (areEqual(root1, root2))
                    printf("Tree 1 and Tree 2 are EQUAL.\n");
                else
                    printf("Tree 1 and Tree 2 are NOT equal.\n");
                break;
            case 4:
                if (areMirror(root1, root2))
                    printf("Tree 1 and Tree 2 are MIRROR images.\n");
                else
                    printf("Tree 1 and Tree 2 are NOT mirror images.\n");
                break;
            case 5:
                copy = copyTree(root1);
                printf("Tree 1 copied successfully.\n");
                break;
            case 6:
                printf("Tree 1 (Inorder): ");
                inorder(root1);
                printf("\nTree 2 (Inorder): ");
                inorder(root2);
                printf("\nCopy (Inorder): ");
                inorder(copy);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
