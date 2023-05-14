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
    {
        return 0;
    }
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

struct BST *modifier(int val, struct BST *node)
{
    node->value = val;
    node->left = BSTcreator(0);
    node->right = BSTcreator(0);
    return node;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    struct BST *root = NULL;
    struct BST *arr[n];
    int j = 1;

    for (int i = 0; i < 2 * n + 1; i++)
    {
        int val;
        scanf("%d", &val);

        if (i == 0)
        {
            root = BSTcreator(val);
            arr[0] = root;
        }
        else
        {
            struct BST *parent = arr[(i - 1) / 2];
            struct BST *node = NULL;
            if (val != -1)
            {
                node = BSTcreator(val);
                arr[j] = node;
                j++;
            }
            if (i % 2 == 1)
            {
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
        }
    }

    int ht = height(root);
    int dia = diameter(root);
    int ans = (dia > ht ? dia - ht : ht - dia);
    printf("%d", ans);

    return 0;
}
