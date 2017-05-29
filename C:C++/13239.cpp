#include <cstdio>
int C[1010][1010];
int main() {
    int i, j;
    for(i=0;i<=1000;i++) {
        C[i][0] = 1;
        for(j=1;j<=i;j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            C[i][j] %= 1000000007;
        }
    }
    int n;
    scanf("%d",&n);
    int x, y;
    for(i=0;i<n;i++) {
        scanf("%d %d",&x,&y);
        printf("%d\n",C[x][y]);
    }
    return 0;
}