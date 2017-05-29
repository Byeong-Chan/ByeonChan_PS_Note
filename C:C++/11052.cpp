#include <cstdio>
#include <algorithm>

using namespace std;

int dp[10010];
int main() {
    int i, j, n;
    int x;
    scanf("%d",&n);
    for(i=1;i<=n;i++) dp[i] = 0;
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        for(j=0;j<n;j++) {
            if(j+i > n) continue;
            dp[j+i] = max(dp[j+i], dp[j] + x);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}