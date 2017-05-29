#include <cstdio>
bool dp[30010];
bool tmp[30010];
int main() {
    int i, j;
    int n, m;
    int x;
    scanf("%d",&n);
    dp[15000] = 1;
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        for (j=0;j<=30000;j++) {
            tmp[j] = dp[j];
            dp[j] = 0;
        }
        for (j=0;j<=30000;j++) {
            if (!tmp[j]) continue;
            dp[j+x] = true;
            dp[j-x] = true;
            dp[j] = true;
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d",&x);
        if (x + 15000 <= 30000 && dp[x+15000]) printf("Y ");
        else printf("N ");
    }
    printf("\n");
    return 0;
}