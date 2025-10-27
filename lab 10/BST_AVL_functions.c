#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* insertBST(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);
    return root;
}

struct Node* searchBST(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->data;
}

int findMax(struct Node* root) {
    struct Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current->data;
}

int getBalance(struct Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct Node* insertAVL(struct Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left = insertAVL(node->left, key);
    else if (key > node->data)
        node->right = insertAVL(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int main() {
    struct Node* bst = NULL;
    struct Node* avl = NULL;
    int choice, val;
    while (1) {
        printf("\n1.Insert(BST)\n2.Traversals(BST)\n3.Search(BST)\n4.Delete(BST)\n5.Min/Max(BST)\n6.Insert(AVL)\n7.Display(AVL)\n8.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                bst = insertBST(bst, val);
                break;
            case 2:
                printf("Inorder: "); inorder(bst);
                printf("\nPreorder: "); preorder(bst);
                printf("\nPostorder: "); postorder(bst);
                printf("\n");
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (searchBST(bst, val))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                bst = deleteNode(bst, val);
                break;
            case 5:
                if (bst) {
                    printf("Min: %d\n", findMin(bst));
                    printf("Max: %d\n", findMax(bst));
                } else printf("Empty Tree\n");
                break;
            case 6:
                printf("Enter value: ");
                scanf("%d", &val);
                avl = insertAVL(avl, val);
                break;
            case 7:
                printf("Inorder (AVL): ");
                inorder(avl);
                printf("\n");
                break;
            case 8:
                exit(0);
        }
    }
}
