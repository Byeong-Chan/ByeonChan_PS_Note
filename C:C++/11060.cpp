#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1010];
int main() {
    int i, j, n;
    int x;
    scanf("%d",&n);
    for(i=2;i<=n;i++) dp[i] = 0x7fffffff;
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        if(x == 0 || dp[i] == 0x7fffffff) continue;
        for(j=1;j<=x;j++) {
            if(i+j > n) break;
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    if(dp[n] != 0x7fffffff) printf("%d\n",dp[n]);
    else printf("-1\n");
    return 0;
}