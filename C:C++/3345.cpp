#include <cstdio>
const long long mod = 1000000009;
int dp[30010], tmp[30010];
char o[30010];
int main() {
    int i, j, n;
    scanf("%d",&n);
    scanf("%s",o);
    if(n & 1) {
        printf("0\n");
        return 0;
    }
    
    dp[0] = 1;
    for(i=0;i<n;i++) {
        for(j=0;j<=i;j++) {
            dp[j] %= mod;
            tmp[j] = dp[j];
            dp[j] = 0;
        }
        if(o[i] == '(') {
            for(j=0;j<=i;j++) {
                dp[j+1] += tmp[j];
                if(j > 0) dp[j-1] += tmp[j];
            }
            continue;
        }
        for(j=0;j<=i;j++) if(j > 0) dp[j-1] += tmp[j];
    }
    printf("%d\n",dp[0]%mod);
    return 0;
}