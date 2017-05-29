#include <cstdio>
int dp[23][310];
int moth[23][310];
int ansd[23];
int o[310][23];
int main() {
    int cnt;
    int ans = 0, tmp = 0;
    int i, j, k;
    int n, m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {
        scanf("%d",&cnt);
        for(j=1;j<=m;j++) scanf("%d",&o[i][j]);
    }
    for(i=1;i<=m;i++) {
        for(j=0;j<=n;j++) {
            dp[i][j] = dp[i-1][j];
            moth[i][j] = j;
        }
        for(j=1;j<=n;j++) {
            for(k=0;k<=n-j;k++) {
                if(dp[i-1][k] + o[j][i] > dp[i][k+j]) {
                    dp[i][k+j] = dp[i-1][k] + o[j][i];
                    moth[i][k+j] = k;
                }
            }
        }
    }
    for(i=0;i<=n;i++) {
        if(ans < dp[m][i]) {
            ans = dp[m][i];
            tmp = i;
        }
    }
    int pre;
    for(i=m;i>=1;i--) {
        pre = tmp;
        tmp = moth[i][tmp];
        ansd[i] = pre - tmp;
    }
    printf("%d\n",ans);
    for(i=1;i<=m;i++) printf("%d ",ansd[i]);
    printf("\n");
    return 0;
}