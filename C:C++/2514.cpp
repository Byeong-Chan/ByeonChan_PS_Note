#include <cstdio>
int o[11][11];
int u[11][11];
int h[11][11];
char a[11][11];
int main()
{
    int i, j, k, l;
    int n = 8, m, w;
    int d, c;
    int sw;
    scanf("%d", &m);
    scanf("%d", &w);
    d = m * 15;
    c = (d % 2 + 1) % 2;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &o[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                u[i][j] += o[i][k] + o[k][j];
            }
            u[i][j] -= o[i][j];
            h[i][j] = u[i][j];
        }
    }
    while (1)
    {
        sw = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (h[i][j] % 2 == c)
                {
                    a[i][j] = '+';
                    for (k = 0; k < n; k++)
                    {
                        for (l = 0; l < n; l++)
                        {
                            if (k == i && l == j) h[k][l] -= 15;
                            else if (k == i || l == j) h[k][l] -= 8;
                            else h[k][l] -= 2;
                        }
                    }
                }
            }
        }
        if (sw == 1) continue;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((d - h[i][j]) % 4 != 0 && a[i][j] != 0) a[i][j] = '-';
                if (a[i][j] == '+' || a[i][j] == '-') printf("%c ", a[i][j]);
                else printf(". ");
            }
            printf("\n");
        }
        break;
    }
    return 0;
}