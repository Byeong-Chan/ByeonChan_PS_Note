#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int i, n;
    int l, r, mid;
    scanf("%d",&n);
    vector<int> dp(n+1, 0x7fffffff), pre(n+1), now(n+1), x(n+1), ans;
    dp[0] = -0x7fffffff;
    now[0] = 0;
    for(i=1;i<=n;i++) {
        scanf("%d",&x[i]);
        l = 0;
        r = n;
        while(l <= r) {
            mid = (l+r) >> 1;
            if(dp[mid] <= x[i]) l = mid + 1;
            else r = mid - 1;
        }
        if(x[i] == dp[l-1]) continue;
        dp[l] = x[i];
        now[l] = i;
        pre[i] = now[l-1];
    }
    for(i=n;i>=1;i--) if(dp[i] != 0x7fffffff) break;
    printf("%d\n",i);
    for(i=now[i];i>0;i=pre[i]) ans.push_back(x[i]);
    while(ans.size()) {
        printf("%d ",ans.back());
        ans.pop_back();
    }
    printf("\n");
    return 0;
}