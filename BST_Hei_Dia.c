#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int value;
    struct BST *left, *right;
};

struct BST *BSTcreator(int val)
{
    struct BST *root = (struct BST *)malloc(sizeof(struct BST));
    root->value = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int height(struct BST *root)
{
    if (root == NULL)
        return 0;
    return (max(height(root->left), height(root->right)) + 1);
}

int diameter(struct BST *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (max(height(root->left) + height(root->right) + 1, max(diameter(root->left), diameter(root->right))));
}

struct Queue
{
    int front;
    int last;
    struct BST **arr;
};

struct Queue *Queuecreator()
{
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->front = -1;
    Q->last = -1;
    Q->arr = (struct BST **)malloc(sizeof(struct BST *));
    return Q;
}
void Enqueue(struct Queue *Q, struct BST *root)
{
    Q->last++;
    Q->arr[Q->last] = root;
    if (Q->front == -1)
    {
        Q->front = 0;
    }
}

struct BST *modifier(int val, struct BST *node)
{
    node->value = val;
    struct BST *left = BSTcreator(0);
    struct BST *right = BSTcreator(0);
    node->left = left;
    node->right = right;
    return node;
}

struct BST *Dequeue(struct Queue *Q)
{
    Q->front++;
    return Q->arr[Q->front - 1];
}

// struct BST *assigner(int n)
// {
//     struct Queue *Q = Queuecreator();
//     struct BST *root = BSTcreator(val);
//     Enqueue(Q, root);
// }

int main()
{
    int n = 0;
    int val = 0;
    int valleft = 0, valright = 0;
    scanf("%d", &n);
    // struct Queue *Q = Queuecreator();
    struct BST *root = BSTcreator(val);
    struct BST *arr[2 * n + 1];
    // Enqueue(Q, root);
    int last = 0;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        scanf("%d", &val);
        // struct BST *node = Dequeue(Q);
        struct BST *node = arr[last];
        last++;
        if (val != -1)
        {
            // node->value = val;
            // struct BST *leftnode = BSTcreator(0);
            // struct BST *rightnode = BSTcreator(0);
            // node->left = leftnode;
            // node->right = rightnode;
            node = modifier(val, node);
            arr[last] = node->left;
            last++;
            arr[last] = node->right;
            // Enqueue(Q, node->left);
            // Enqueue(Q, node->right);
        }
        else
        {
            node = NULL;
        }
    }

    int ht = height(root);
    int dia = diameter(root);
    int ans = (dia > ht ? dia - ht : ht - dia);
    printf("%d %d %d", dia, ht, ans);

    return 0;
}