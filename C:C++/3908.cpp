#include <cstdio>
int prime[1120];
long long dp[3123][15];
bool chk[1123];
int main() {
    int i, j, k;
    int m = 0;
    chk[1] = true;
    for(i=2;i<=1120;i++) {
        if(chk[i]) continue;
        prime[m++] = i;
        for(j=i*i;j<=1120;j+=i) chk[j] = true;
    }
    dp[0][0] = 1;
    for(i=0;i<m;i++) for(j=1120;j>=0;j--) for(k=0;k<14;k++) dp[j+prime[i]][k+1] += dp[j][k];
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, m;
        scanf("%d %d",&n,&m);
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}