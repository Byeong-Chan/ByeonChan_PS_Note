#include <cstdio>
#include <algorithm>
using namespace std;
int even[1000010];
int odd[1000010];
int dp[2], tmp[2];
int main() {
    int i, n, k, x;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        (x & 1) ? odd[i % k]++ : even[i % k]++;
    }
    dp[1] = 1000001;
    for(i=0;i<k;i++) {
        tmp[0] = dp[0];
        tmp[1] = dp[1];
        dp[0] = dp[1] = 1000001;
        dp[0] = min(dp[0], tmp[0] + odd[i]);
        dp[0] = min(dp[0], tmp[1] + even[i]);
        dp[1] = min(dp[1], tmp[0] + even[i]);
        dp[1] = min(dp[1], tmp[1] + odd[i]);
    }
    printf("%d\n",dp[0]);
    return 0;
}