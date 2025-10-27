#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

typedef struct queue {
    Node* data[100];
    int front, rear;
} Queue;

Node* createTree();
void levelOrderTraversal(Node* root);
void enqueue(Queue* q, Node* n);
Node* dequeue(Queue* q);
int isEmpty(Queue* q);

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
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    Queue q;
    q.front = q.rear = -1;

    enqueue(&q, root);

    printf("Level Order Traversal: ");
    while (!isEmpty(&q)) {
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(&q, curr->left);
        if (curr->right)
            enqueue(&q, curr->right);
    }
    printf("\n");
}

void enqueue(Queue* q, Node* n) {
    q->data[++(q->rear)] = n;
}

Node* dequeue(Queue* q) {
    return q->data[++(q->front)];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}
int main() {
    Node* root = NULL;
    printf("=== Create Binary Tree ===\n");
    root = createTree();

    printf("\n=== Level-Order Traversal ===\n");
    levelOrderTraversal(root);

    return 0;
}
