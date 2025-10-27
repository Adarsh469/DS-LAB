#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int data);
Node* createTree();
void inorderIterative(Node* root);
void preorderIterative(Node* root);
void postorderIterative(Node* root);
void printParent(Node* root, int value);
int height(Node* root);
int countLeafNodes(Node* root);
int printAncestors(Node* root, int value);
void menu();

typedef struct Stack {
    Node* data[100];
    int top;
} Stack;

void push(Stack *s, Node* node) {
    s->data[++(s->top)] = node;
}

Node* pop(Stack *s) {
    return s->data[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

typedef struct Queue {
    Node* data[100];
    int front, rear;
} Queue;

void enqueue(Queue* q, Node* node) {
    q->data[++(q->rear)] = node;
}

Node* dequeue(Queue* q) {
    return q->data[++(q->front)];
}

int isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    Node* root = createNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = createTree();
    printf("Enter right child of %d:\n", data);
    root->right = createTree();

    return root;
}

void inorderIterative(Node* root) {
    Stack s;
    s.top = -1;
    Node* curr = root;

    while (curr != NULL || !isEmpty(&s)) {
        while (curr != NULL) {
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

void preorderIterative(Node* root) {
    if (root == NULL) return;
    Stack s;
    s.top = -1;
    push(&s, root);

    while (!isEmpty(&s)) {
        Node* curr = pop(&s);
        printf("%d ", curr->data);
        if (curr->right) push(&s, curr->right);
        if (curr->left) push(&s, curr->left);
    }
    printf("\n");
}

void postorderIterative(Node* root) {
    if (root == NULL) return;
    Stack s1, s2;
    s1.top = s2.top = -1;
    push(&s1, root);

    while (!isEmpty(&s1)) {
        Node* curr = pop(&s1);
        push(&s2, curr);
        if (curr->left) push(&s1, curr->left);
        if (curr->right) push(&s1, curr->right);
    }

    while (!isEmpty(&s2)) {
        printf("%d ", pop(&s2)->data);
    }
    printf("\n");
}

void printParent(Node* root, int value) {
    if (root == NULL) return;
    if ((root->left && root->left->data == value) ||
        (root->right && root->right->data == value)) {
        printf("Parent of %d is %d\n", value, root->data);
        return;
    }
    printParent(root->left, value);
    printParent(root->right, value);
}
int height(Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int printAncestors(Node* root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;

    if (printAncestors(root->left, value) || printAncestors(root->right, value)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// Menu
void menu() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n===== Binary Tree Operations =====\n");
        printf("1. Create Binary Tree (Recursive)\n");
        printf("2. Inorder Traversal (Iterative)\n");
        printf("3. Preorder Traversal (Iterative)\n");
        printf("4. Postorder Traversal (Iterative)\n");
        printf("5. Print Parent of an Element\n");
        printf("6. Print Depth (Height) of Tree\n");
        printf("7. Print Ancestors of an Element\n");
        printf("8. Count Leaf Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderIterative(root);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderIterative(root);
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderIterative(root);
                break;
            case 5:
                printf("Enter value: ");
                scanf("%d", &value);
                printParent(root, value);
                break;
            case 6:
                printf("Depth (Height) of tree: %d\n", height(root));
                break;
            case 7:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Ancestors of %d: ", value);
                if (!printAncestors(root, value))
                    printf("No such element found.");
                printf("\n");
                break;
            case 8:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
