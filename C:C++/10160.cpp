#include <stdio.h>
int n, m;
long long int submat[7][7] = { -1, 1, 0, 0, 0, 0, 0,
-2, 1, 1, 0, 0, 0, 0,
-2, 0, 0, 1, 0, 1, 0,
-2, 1, 0, 0, 1, 0, 0,
-2, 0, 0, 1, 0, 0, 0,
-2, 1, 0, 0, 0, 0, 1,
-2, 1, 0, 0, 0, 0, 0 };
long long int mat[7][7] = { 1, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0,
0, 0, 1, 0, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 1, 0, 0,
0, 0, 0, 0, 0, 1, 0,
0, 0, 0, 0, 0, 0, 1 };
long long int tmpmat[7][7] = { 0, };
long long int e = 0;
bool _bin[23];
int main()
{
    int i, j, l;
    int k;
    int leng = 0;
    scanf("%d %d", &n, &m);
    if (n < 5) {
        for (i = 0, j = 1; i < n; i++, j *= m);
        printf("%d", j);
        return 0;
    }
    for (i = 0; i < 7; i++) submat[i][0] += m;
    for (i = n; i >= 1; i >>= 1) _bin[leng++] = (bool)(i & 1);
    for (k = leng - 1; k >= 0; k--) {
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                for (l = 0; l < 7; l++) {
                    tmpmat[i][j] += mat[i][l] * mat[l][j];
                }
                tmpmat[i][j] %= 1000000009;
            }
        }
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                mat[i][j] = tmpmat[i][j];
                tmpmat[i][j] = 0;
            }
        }
        if (!_bin[k]) continue;
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                for (l = 0; l < 7; l++) {
                    tmpmat[i][j] += mat[i][l] * submat[l][j];
                }
                tmpmat[i][j] %= 1000000009;
            }
        }
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                mat[i][j] = tmpmat[i][j];
                tmpmat[i][j] = 0;
            }
        }
    }
    for (i = 0; i < 7; i++) {
        e += mat[0][i];
    }
    e %= 1000000009;
    printf("%lld", e);
    return 0;
}