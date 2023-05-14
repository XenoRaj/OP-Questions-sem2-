#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    char arr[m][n + 1];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", &arr[i]);
    }

    int max = 0;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '.')
            {
                sum++;
            }
            else
            {
                if (sum > max)
                {
                    max = sum;
                }
                sum = 0;
            }
        }
        if (sum > max)
        {
            max = sum;
        }
    }

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[j][i] == '.')
            {
                sum++;
            }
            else
            {
                if (sum > max)
                {
                    max = sum;
                }
                sum = 0;
            }
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    int ans = 2 * max + 1;
    printf("%d", ans);
}