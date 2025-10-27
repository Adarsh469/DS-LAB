#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

void BSTtoDLL(struct Node* root, struct Node** head_ref) {
    static struct Node* prev = NULL;
    if (root == NULL) return;
    BSTtoDLL(root->left, head_ref);
    if (prev == NULL) *head_ref = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BSTtoDLL(root->right, head_ref);
}

int main() {
    struct Node* root = NULL;
    struct Node* head = NULL;
    int choice, val;
    while (1) {
        printf("\n1.Insert\n2.Convert to DLL\n3.Display DLL\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                head = NULL;
                BSTtoDLL(root, &head);
                printf("BST converted to DLL\n");
                break;
            case 3: {
                struct Node* temp = head;
                printf("Doubly Linked List: ");
                while (temp) {
                    printf("%d ", temp->data);
                    temp = temp->right;
                }
                printf("\n");
                break;
            }
            case 4:
                exit(0);
        }
    }
}
