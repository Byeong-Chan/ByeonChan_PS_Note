#include <cstdio>

const int INF = 0x7fffffff;

int d[110][110];
int main() {
    int i, j, k;
    int n, m;
    int x, y, z;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) d[i][j] = INF;
        d[i][i] = 0;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        if(d[x][y] > z) d[x][y] = z;
    }
    for(k=1;k<=n;k++) {
        for(i=1;i<=n;i++) {
            if(d[i][k] == 0x7fffffff) continue;
            for(j=1;j<=n;j++) {
                if(d[k][j] == 0x7fffffff) continue;
                if(d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(d[i][j] == INF) printf("0 ");
            else printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    return 0;
}