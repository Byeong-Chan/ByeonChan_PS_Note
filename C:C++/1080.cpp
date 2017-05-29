#include <cstdio>
int o[51][51], u[51][51];
int main() {
    int i, j, k, l;
    int n, m;
    int ans = 0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%1d",&o[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%1d",&u[i][j]);
        }
    }
    for(i=0;i<=n-3;i++) {
        for(j=0;j<=m-3;j++) {
            if(o[i][j] == u[i][j]) continue;
            else {
                for(k=i;k<i+3;k++) {
                    for(l=j;l<j+3;l++) {
                        o[k][l] = 1 - o[k][l];
                    }
                }
                ans++;
            }
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(o[i][j] != u[i][j]) break;
        }
        if(j < m) break;
    }
    if(i < n) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}