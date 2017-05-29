#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dp[1 << 22], o[1 << 22];
int Abs(int x) {
    return x < 0 ? -x : x;
}
int main() {
    int i, n;
    int k;
    int p;
    int d;
    int ans = 0;
    int tmp;
    scanf("%d",&n);
    n++;
    k = 1 << n;
    p = k >> 1;
    for(i=2;i<k;i++) {
        scanf("%d",&o[i]);
        ans += o[i];
    }
    for(i=k-1;i>=2;i--) {
        tmp = o[i] + dp[i];
        d = i >> 1;
        if(dp[d] == 0) dp[d] = tmp;
        else {
            ans += Abs(dp[d] - tmp);
            dp[d] = max(dp[d], tmp);
        }
    }
    printf("%d\n",ans);
    return 0;
}