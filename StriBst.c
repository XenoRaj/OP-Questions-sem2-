#include <stdio.h>
#include <stdlib.h>

struct StringBst
{
    char *str;
    struct StringBst *left, *right;
};

struct StringBst *creator(char *str)
{
    struct StringBst *root = (struct StringBst *)malloc(sizeof(struct StringBst));
    root->str = (char *)malloc(30 * sizeof(char));
    root->str = str;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int len(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int comparepref(char *str, char *pref)
{
    int l1 = len(str);
    int l2 = len(pref);

    if (l2 <= l1)
    {
        for (int i = 0; i < l2; i++)
        {
            if (pref[i] > str[i])
            {
                return 1;
            }
            if (pref[i] < str[i])
            {
                return -1;
            }
        }
        return 0;
    }

    if (l2 > l1)
    {
        for (int i = 0; i < l1; i++)
        {
            if (pref[i] > str[i])
            {
                return 1;
            }
            if (pref[i] < str[i])
            {
                return -1;
            }
        }
        return 1;
    }
}

int comparestr(char *str1, char *str2)
{
    int l1 = len(str1);
    int l2 = len(str2);
    int l3 = l1 > l2 ? l2 : l1;
    for (int i = 0; i < l3; i++)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    if (l3 == l1 && l3 == l2)
    {
        return 0;
    }
    else if (l3 == l1)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

struct StringBst *insert(struct StringBst *root, char *str)
{
    struct StringBst *node = root;
    if (node == NULL)
    {
        node = creator(str);
    }
    else
    {
        if (comparestr(node->str, str) == -1)
        {
            node->right = insert(node->right, str);
        }
        else
        {
            node->left = insert(node->left, str);
        }
    }
    return node;
}

struct StringBst *FindMin(struct StringBst *root)
{
    struct StringBst *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

struct StringBst *deleteexact(struct StringBst *root, char *str)
{
    struct StringBst *node = root;
    if (node->left == NULL)
    {
        if (comparestr(node->str, str) == 0)
        {
            node = node->right;
        }
        return node;
    }
    node->left = deleteexact(node->left, str);
    return node;
}

struct StringBst *delete(struct StringBst *root, char *str)
{
    struct StringBst *node = root;
    if (node == NULL)
    {
        return NULL;
    }

    node->left = delete (node->left, str);
    node->right = delete (node->right, str);
    if (comparepref(node->str, str) == 0)
    {
        if (node->left == NULL)
        {
            node = node->right;
        }
        else if (node->right == NULL)
        {
            node = node->left;
        }
        else
        {
            struct StringBst *minode = node->right;
            while (minode->left != NULL)
            {
                minode = minode->left;
            }
            node->str = minode->str;
            node->right = deleteexact(node->right, minode->str);
        }
    }

    return node;
}

int Find(struct StringBst *root, char *str)
{
    struct StringBst *curr = root;
    int flag = 0;
    int trueflag = 0;
    if (curr == NULL)
    {
        return 0;
    }
    flag = Find(root->left, str);
    if (flag == 1)
    {
        trueflag = 1;
    }

    if (comparepref(curr->str, str) == 0)
    {
        printf("%s\n", curr->str);
        flag = 1;
    }
    if (flag == 1)
    {
        trueflag = 1;
    }
    flag = Find(root->right, str);
    if (flag == 1)
    {
        trueflag = 1;
    }

    return trueflag;
}

int notprinterfind(struct StringBst *root, char *str)
{
    struct StringBst *curr = root;
    int flag = 0;
    int trueflag = 0;
    if (curr == NULL)
    {
        return 0;
    }
    flag = notprinterfind(root->left, str);
    if (flag == 1)
    {
        trueflag = 1;
    }

    if (comparepref(curr->str, str) == 0)
    {
        // printf("%s", curr->str);
        flag = 1;
    }
    if (flag == 1)
    {
        trueflag = 1;
    }

    flag = notprinterfind(root->right, str);
    if (flag == 1)
    {
        trueflag = 1;
    }
    return trueflag;
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    struct StringBst *root = NULL;
    for (int i = 0; i < N; i++)
    {
        char *strr = (char *)malloc(30 * sizeof(char));
        scanf("%s", strr);
        root = insert(root, strr);
    }

    for (int x = 0; x < Q; x++)
    {
        int flag = 0;
        char *op = (char *)malloc(10 * sizeof(char));
        char *str1 = (char *)malloc(30 * sizeof(char));
        scanf("%s", op);
        scanf("%s", str1);
        if (comparestr(op, "Delete") == 0)
        {
            flag = notprinterfind(root, str1);
            if (flag == 1)
            {
                root = delete (root, str1);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (comparestr(op, "Find") == 0)
        {
            flag = Find(root, str1);
            if (flag != 1)
            {
                printf("-1\n");
            }
        }
    }
}