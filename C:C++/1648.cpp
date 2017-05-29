#include <cstdio>
short dp[1<<14], tmp[1<<14];
int main() {
    int i, j;
    int maxd;
    int nxt;
    int k;
    int n, m;
    scanf("%d %d",&n,&m);
    k = 1 << (m-1);
    maxd = (1 << m) - 1;
    
    dp[maxd] = 1;
    for(i=n*m;i>0;i--) {
        for(j=(1<<m)-1;j>=0;j--) {
            tmp[j] = dp[j] % 9901;
            dp[j] = 0;
        }
        for(j=(1<<m)-2;j>=0;j--) {
            if(i%m == 0) {
                nxt = j>>1;
                if((j & 1) == 0) dp[nxt + k] += tmp[j];
                else dp[nxt] += tmp[j];
                continue;
            }
            nxt = j >> 1;
            if((j & 1) == 0) dp[nxt + k] += tmp[j];
            else {
                if((j & (1 << (m-1))) == 0) dp[nxt + k + (k >> 1)] += tmp[j];
                dp[nxt] += tmp[j];
            }
        }
        dp[maxd>>1] += tmp[maxd];
    }
    printf("%hd\n",(short)(dp[maxd]%9901));
    return 0;
}