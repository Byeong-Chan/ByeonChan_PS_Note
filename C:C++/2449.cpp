#include <stdio.h>
int u[202];
int table[210][210];
int o[202];
int main()
{
    int i, j, k, l, n, g;
    int a, pr;
    int m = 0;
    int tmp_max = 0, tmp_max2 = 0;
    int max1 = 0;
  
    scanf("%d %d", &n, &g);
    scanf("%d", &a);
    u[m++] = a;
    pr = a;
    for (i = 0; i<n-1; i++) {
        scanf("%d", &a);
        if (pr != a) u[m++] = a;
        pr = a;
    }
    for (i = 1; i<m; i++) {
        for (j = i-1; j >= 0; j--) {
            tmp_max = 0;
            for (k = i - 1; k >= j + 2; k--) {
                for (l = k - 1; l >= j + 1; l--) {
                    if (table[k][l] > tmp_max) tmp_max = table[k][l];
                }
            }
            if (u[i] == u[j]) tmp_max++;
  
            for (k = j - 1; k >= 0; k--) {
                if (tmp_max + table[j][k] > table[i][k]) table[i][k] = tmp_max + table[j][k];
            }
            if (table[i][j] < tmp_max) table[i][j] = tmp_max;
  
            if (table[i][j] > max1) max1 = table[i][j];
        }
    }
    printf("%d", m - max1 -1);
    return 0;
}