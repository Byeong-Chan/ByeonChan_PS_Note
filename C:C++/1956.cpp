#include <cstdio>
int dist[410][410];
const int INT_MAX = 0x7fffffff;
int main() {
    int x, y, z;
    int k, i, j;
    int n, m;
    int ans = INT_MAX;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) dist[i][j] = INT_MAX;
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        dist[x][y] = z;
    }
    for(k=1;k<=n;k++) {
        for(i=1;i<=n;i++) {
            if(dist[i][k] == 0x7fffffff) continue;
            for(j=1;j<=n;j++) {
                if(dist[k][j] == 0x7fffffff) continue;
                if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for(i=1;i<=n;i++) if(dist[i][i] < ans) ans = dist[i][i];
    if(ans != INT_MAX) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}