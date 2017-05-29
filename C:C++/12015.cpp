#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int i, n;
    int l, r, mid;
    int x;
    scanf("%d",&n);
    vector<int> dp(n+1, 0x7fffffff);
    dp[0] = -0x7fffffff;
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        l = 0;
        r = n;
        while(l <= r) {
            mid = (l+r) >> 1;
            if(dp[mid] <= x) l = mid + 1;
            else r = mid - 1;
        }
        if(x == dp[l-1]) continue;
        dp[l] = x;
    }
    for(i=n;i>=1;i--) if(dp[i] != 0x7fffffff) break;
    printf("%d\n",i);
    return 0;
}