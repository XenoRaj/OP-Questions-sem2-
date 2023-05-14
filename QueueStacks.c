#include <stdio.h>
#include <string.h>
#define max_elements 100

struct Queue
{
    int arr[max_elements];
    int front;
    int rear;
};

struct Queue Create_Queue()
{
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int Queue_Empty(struct Queue *q)
{
    if (q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Queue_Full(struct Queue *q)
{
    if (q->rear == max_elements)
        return 1;
    else
        return 0;
}

void Enqueue(struct Queue *q, int k)
{
    if (!Queue_Full(q))
    {
        q->rear++;
        q->arr[q->rear] = k;
        if (q->front == -1)
            q->front = 0;
    }
    else
        printf("-1\n");
}

void Dequeue(struct Queue *q)
{
    if (Queue_Empty(q))
    {
        printf("-1\n");
    }
    else
    {
        q->front++;
    }
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
}

void Display(struct Queue *q)
{
    if (Queue_Empty(q))
    {
        printf("-1\n");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

struct Stack
{
    struct Queue arr[max_elements];
    int last;
};

struct Stack Create_Stack()
{
    struct Stack s;
    s.last = -1;
    return s;
}

int Stack_Empty(struct Stack *s)
{
    if (s->last == -1)
        return 1;
    else
        return 0;
}

int Stack_Full(struct Stack *s)
{
    if (s->last == max_elements - 1)
        return 1;
    else
        return 0;
}

void Enstack(struct Stack *s, struct Queue k)
{
    if (Stack_Full(s))
    {
        printf("-1\n");
    }
    else
    {
        s->last++;
        s->arr[s->last] = k;
    }
}

void Destack(struct Stack *s)
{
    if (Stack_Empty(s))
    {
        return;
    }
    else
        s->last--;
}

void Push(struct Stack *s, int k)
{
    struct Queue q = Create_Queue();
    Enqueue(&q, k);
    Enstack(s, q);
}

void StackEnqueue(struct Stack *s, int k)
{
    if (Stack_Empty(s))
    {
        Push(s, k);
    }
    else
    {
        Enqueue(&(s->arr[s->last]), k);
    }
}

void Pop(struct Stack *s)
{
    Destack(s);
}

void StackDequeue(struct Stack *s)
{
    if (Stack_Empty(s))
    {
        printf("-1\n");
    }
    else
    {
        struct Queue *q = &(s->arr[s->last]);
        printf("%d\n", q->arr[q->front]);
        Dequeue(q);
        if (Queue_Empty(q))
        {
            Pop(s);
        }
    }
}

void Max_Sum_Pairs(struct Stack *s, int k)
{
    if (Stack_Empty(s))
    {
        printf("-1");
    }
    else
    {
        struct Queue *q = &(s->arr[s->last]);
        int ctr = 0;
        for (int i = q->front; i < q->rear - 1; i++)
        {
            if (q->arr[i] + q->arr[i + 1] >= k)
                ctr++;
        }
        printf("%d\n", ctr);
        Pop(s);
    }
}

int main()
{
    int Q;
    scanf("%d", &Q);
    int k;
    char str[30];
    struct Stack s = Create_Stack();
    for (; Q > 0; Q--)
    {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0)
        {
            scanf("%d\n", &k);
            Push(&s, k);
        }
        else if (strcmp(str, "Enqueue") == 0)
        {
            scanf("%d\n", &k);
            StackEnqueue(&s, k);
        }
        else if (strcmp(str, "Dequeue") == 0)
        {
            StackDequeue(&s);
        }
        else if (strcmp(str, "Pop") == 0)
        {
            Pop(&s);
        }
        else if (strcmp(str, "MaxSumPairs") == 0)
        {
            scanf("%d", &k);
            Max_Sum_Pairs(&s, k);
        }
        else
        {
            printf("Wrong Input.");
            Q++;
        }
    }
    return 0;
}