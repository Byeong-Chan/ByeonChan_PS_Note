#include <cstdio>
int dt[66][66];
void sub(int x, int y, int n) {
    int tmp = dt[x][y] - dt[x-n][y] - dt[x][y-n] + dt[x-n][y-n];
    if (tmp == 0 || tmp == n*n) {
        if (tmp == 0) printf("0");
        else printf("1");
    }
    else {
        int m = n >> 1;
        printf("(");
        sub(x - m, y - m, m);
        sub(x - m, y, m);
        sub(x, y - m, m);
        sub(x, y, m);
        printf(")");
    }
}
int main() {
    int i, j;
    int x;
    int n;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%1d",&x);
            dt[i][j] = x;
            dt[i][j] += dt[i-1][j] + dt[i][j-1] - dt[i-1][j-1];
        }
    }
    sub(n, n, n);
    printf("\n");
    return 0;
}