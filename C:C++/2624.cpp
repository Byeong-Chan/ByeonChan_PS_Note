#include <cstdio>
long long dp[10010];
long long tmp[10010];
int val[110], coin[110];
int main() {
    int i, j, n, k;
    int x;
    scanf("%d%d",&k,&n);
    for(i=0;i<n;i++) {
        scanf("%d %d",&val[i],&coin[i]);
    }
    dp[0] = 1;
    for(i=0;i<n;i++) {
        for(j=0;j<=k;j++) tmp[j] = 0;
        x = val[i] * coin[i] + val[i];
        for(j=k;j>=0;j--) {
            if(j+x > k) continue;
            tmp[j+x] += dp[j];
        }
        for(j=0;j<=k;j++) {
            if(j+val[i] > k) continue;
            tmp[j+val[i]] += tmp[j];
            dp[j+val[i]] += dp[j];
        }
        for(j=0;j<=k;j++) dp[j] -= tmp[j];
    }
    printf("%lld\n",dp[k]);
    return 0;
}