#include <stdio.h>

// int max(int a, int b, int c)
// {

//     if (a > b && a > c)
//         return a;
//     else if (b > a && b > c)
//         return b;
//     else
//         return c;
// }

int main()
{
    int ishu = 0, rohu = 0;
    int n;
    int k;
    int cards[100000];
    scanf("%d %d", &n, &k);
    int m;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        cards[i] = m;
    }

    for (int i = 0; i < n - k + 1; i += 2)
    {
        max = -1;
        if (max == -1)
        {
            for (int j = i; j < i + k; j++)
            {
                if (max < cards[j])
                {
                    max = cards[j];
                }
            }
        }
        else
        {
            if (cards[i + k - 1] > max)
            {
                max = cards[i + k - 1];
            }
        }

        ishu += max;
        if (max == cards[i])
        {
            max = -1;
        }
        if (i - n + k == 0)
        {
            break;
        }

        if (max == -1)
        {
            for (int j = i + 1; j < i + k + 1; j++)
            {
                if (max < cards[j])
                {
                    max = cards[j];
                }
            }
        }
        else
        {
            if (cards[i + k] > max)
            {
                max = cards[i + k];
            }
        }

        rohu += max;
        if (max == cards[i + 1])
        {
            max = -1;
        }
    }
    if (ishu == rohu)
    {
        printf("draw");
    }
    else if (ishu > rohu)
    {
        printf("ishu");
    }
    else
    {
        printf("rohu");
    }

    return 0;
}