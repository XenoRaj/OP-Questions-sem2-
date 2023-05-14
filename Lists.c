#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *creator(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void KthNode(struct Node *head, int K, int n)
{
    if (K > n)
    {
        printf("-1\n");
        return;
    }
    struct Node *curr = head;
    for (int i = 0; i < K - 1; i++)
    {
        if (curr == NULL)
        {
            printf("-1\n");
            return;
        }
        else
        {
            curr = curr->next;
        }
    }

    printf("%d\n", curr->data);
}

int delete(struct Node **head, int K, int n)
{
    if (K > n)
    {
        printf("-1\n");
        return n;
    }
    struct Node *curr = *head;
    struct Node *prev = NULL;
    if (K == 1)
    {
        *head = curr->next;
        return n - 1;
    }
    for (int i = 0; i < K - 1; i++)
    {
        if (curr == NULL)
        {
            printf("-1\n");
            return n;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    prev->next = curr->next;
    return n - 1;
}

void add(struct Node **head, int K, int X, int n)
{
    if (K > n)
    {
        printf("-1\n");
        return;
    }
    struct Node *curr = *head;
    for (int i = 0; i < K - 1; i++)
    {
        if (curr == NULL)
        {
            printf("-1\n");
            return;
        }
        else
        {
            curr = curr->next;
        }
    }
    curr->data += X;
}

void sub(struct Node **head, int K, int X, int n)
{
    if (K > n)
    {
        printf("-1\n");
        return;
    }
    struct Node *curr = *head;
    for (int i = 0; i < K - 1; i++)
    {
        if (curr == NULL)
        {
            printf("-1\n");
            return;
        }
        else
        {
            curr = curr->next;
        }
    }
    curr->data -= X;
}

void xor (struct Node * head, int K, int n) {
    struct Node *curr = head;
    if (K > n)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n - K; i++)
    {
        if (curr == NULL)
        {
            printf("-1\n");
            return;
        }
        else
        {
            curr = curr->next;
        }
    }
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        ans = ans ^ curr->data;
        curr = curr->next;
    }
    printf("%d\n", ans);
}

    int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int data = 0;
    scanf("%d", &data);
    struct Node *head = creator(data);
    struct Node *curr = head;
    struct Node *temp = NULL;

    for (int i = 1; i < N; i++)
    {
        scanf("%d", &data);
        temp = creator(data);
        curr->next = temp;
        curr = curr->next;
    }
    char op[100];
    int K = 0;
    int X = 0;
    for (; Q > 0; Q--)
    {
        scanf("%s", op);
        if (strcmp(op, "KthNode") == 0)
        {
            scanf("%d", &K);
            KthNode(head, K, N);
        }
        else if (strcmp(op, "Delete") == 0)
        {
            scanf("%d", &K);
            N = delete (&head, K, N);
        }
        else if (strcmp(op, "Add") == 0)
        {
            scanf("%d %d", &K, &X);
            add(&head, K, X, N);
        }
        else if (strcmp(op, "Subtract") == 0)
        {
            scanf("%d %d", &K, &X);
            sub(&head, K, X, N);
        }
        else if (strcmp(op, "Xor") == 0)
        {
            scanf("%d", &K);
            xor(head, K, N);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}