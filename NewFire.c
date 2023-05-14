#include <stdio.h>
#include <stdlib.h>

int spread(int m, int n, int burning[m * n][2], int pcount, int houses[m + 2][n + 2], int count)
{
    for (int i = burning[pcount][0] - 1; i <= burning[pcount][0] + 1; i++)
    {
        for (int j = burning[pcount][1] - 1; j <= burning[pcount][1] + 1; j++)
        {
            if (houses[i][j] == 0)
            {
                houses[i][j] = 1;
                burning[count][0] = i;
                burning[count][1] = j;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    // int **houses = (int **)malloc((m + 2) * sizeof(int *));
    // for (int i = 0; i < m + 2; i++)
    // {
    //     houses[i] = (int *)malloc((n + 2) * sizeof(int));
    //     for (int j = 0; j < n + 2; j++)
    //     {
    //         houses[i][j] = 0;
    //     }
    // }
    int houses[m + 2][n + 2];

    int burning[m * n][2];
    // int **burning = (int **)malloc((m * n) * sizeof(int *));
    // for (int i = 0; i < m * n; i++)
    // {
    //     burning[i] = (int *)malloc((2) * sizeof(int));
    //     burning[i][0] = -1;
    //     burning[i][1] = -1;
    // }
    int count = 0;
    for (int i = 0; i < n + 2; i++)
    {
        houses[0][i] = -1;
        houses[m + 1][i] = -1;
    }
    for (int i = 0; i < m + 2; i++)
    {
        houses[i][0] = -1;
        houses[i][n + 1] = -1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &houses[i][j]);
            if (houses[i][j] == 1)
            {
                burning[count][0] = i;
                burning[count][1] = j;
                count++;
            }
        }
    }

    int pcount = 0;
    int lcount = count;

    int ctr = 0;
    while (count < m * n)
    {
        for (; pcount < lcount; pcount++)
        {
            count = spread(m, n, burning, pcount, houses, count);
            if (count == m * n)
                break;
        }
        lcount = count;
        ctr++;
        if (count == m * n)
            break;
    }
    printf("%d", ctr);
}