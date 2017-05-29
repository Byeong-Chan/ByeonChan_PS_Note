#include <cstdio>
int dist[510][510];
int dp[510][510];
int main() {
    int i, j, k;
    int n, m, c;
    int x, y, z;
    int ans = 1;
    scanf("%d %d %d",&n,&m,&c);    for(i=0;i<c;i++) {
        scanf("%d %d %d",&x,&y,&z);
        if(dist[x][y] < z) dist[x][y] = z;
    }
    
    dp[1][1] = 1;
    for(i=1;i<n;i++) {
        for(j=1;j<m;j++) {
            if(dp[i][j] == 0) continue;
            for(k=i+1;k<=n;k++) {
                if(dist[i][k] == 0) continue;
                if(dp[k][j+1] < dp[i][j] + dist[i][k]) dp[k][j+1] = dp[i][j] + dist[i][k];
            }
        }
    }
    for(i=2;i<=m;i++) {
        if(dp[n][i] > ans) ans = dp[n][i];
    }
    printf("%d\n",ans-1);
    return 0;
}