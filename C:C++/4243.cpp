#include <cstdio>
#include <algorithm>
using namespace std;
const long long INF = (long long)0x7fffffff << 30;
long long hap[110];
long long dp[110][2];
long long tmp[110][2];
int main() {
    int i, j, n;
    int m;
    int t;
    int st, ed;
    long long sum, s;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        scanf("%d",&m);
        for(i=1;i<n;i++) {
            scanf("%lld",&hap[i]);
            hap[i] += hap[i-1];
        }
        for(i=n;i>0;i--) dp[i][0] = dp[i][1] = INF;
        dp[m][0] = dp[m][1] = 0;
        for(i=1;i<n;i++) {
            for(j=n-i+1;j>0;j--) {
                tmp[j][0] = dp[j][0];
                tmp[j][1] = dp[j][1];
                dp[j][0] = dp[j][1] = INF;
            }
            sum = n-i;
            for(st=n-i;st>0;st--) {
                ed = st+i;
                
                s = hap[ed-1] - hap[st-1];
                if(tmp[st][0] != INF) dp[st][1] = min(dp[st][1], tmp[st][0] + sum * s);
                if(tmp[st+1][1] != INF) dp[st][0] = min(dp[st][0], tmp[st+1][1] + sum * s);
                
                s = hap[ed-1] - hap[ed-2];
                if(tmp[st][1] != INF) dp[st][1] = min(dp[st][1], tmp[st][1] + sum * s);
                s = hap[st] - hap[st-1];
                if(tmp[st+1][0] != INF) dp[st][0] = min(dp[st][0], tmp[st+1][0] + sum * s);
            }
        }
        printf("%lld\n",min(dp[1][0], dp[1][1]));
    }
    return 0;
}