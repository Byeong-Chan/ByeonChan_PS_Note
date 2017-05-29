#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[120][120];
int main() {
    int n;
    int x;
    int i, j;
    scanf("%d",&n);
    dp[0][0] = 1;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&x);
            if(x == 0) continue;
            dp[i+x][j] += dp[i][j];
            dp[i][j+x] += dp[i][j];
        }
    }
    printf("%lld\n",dp[n-1][n-1]);
    return 0;
}