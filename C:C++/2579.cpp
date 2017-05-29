#include <cstdio>
#include <algorithm>

using namespace std;

int dp[310][2];
int main() {
    int i, n;
    int x;
    scanf("%d",&n);
    for(i=2;i<=n+1;i++) {
        scanf("%d",&x);
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + x;
        dp[i][1] = dp[i-1][0] + x;
    }
    printf("%d\n",max(dp[n+1][0], dp[n+1][1]));
    return 0;
}