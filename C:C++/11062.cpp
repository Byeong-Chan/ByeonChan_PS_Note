#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1010], tmp[1010];
int hap[1010];
int main() {
    int t;
    int i, j, n;
    int st, ed;
    int s;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
            scanf("%d",&hap[i]);
            dp[i] = hap[i];
            hap[i] += hap[i-1];
        }
        for(i=1;i<n;i++) {
            for(j=n-i+1;j>0;j--) {
                tmp[j] = dp[j];
                dp[j] = 0;
            }
            for(st=n-i;st>0;st--) {
                ed = st + i;
                s = hap[ed] - hap[st-1];
                dp[st] = max(s - tmp[st], s - tmp[st+1]);
            }
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}