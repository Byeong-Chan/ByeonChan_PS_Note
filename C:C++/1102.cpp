#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1<<16];
int sc[16][16];
char o[17];
void dfs(int n, int dp[], int a, int b, int sum) {
    if(n - a < b) return;
    if(a == n) {
        if(dp[sum] == -1) return;
        int i, j;
        for(i=0;i<n;i++) {
            if((sum & (1 << i)) == 0) continue;
            for(j=0;j<n;j++) {
                if(i == j) continue;
                if(sum & (1 << j)) continue;
                if(dp[sum + (1 << j)] == -1) dp[sum + (1 << j)] = 0x7fffffff;
                dp[sum + (1 << j)] = min(dp[sum + (1 << j)], dp[sum] + sc[i][j]);
            }
        }
        return;
    }
    if(b > 0) dfs(n, dp, a+1, b-1, sum + (1<<a));
    dfs(n, dp, a+1, b, sum);
}
int main() {
    int sum = 0;
    int hap = 0;
    int k, i, j;
    int n;
    int p;
    int ans = 0x7fffffff;
    memset(dp, -1, sizeof(dp));
    scanf("%d",&n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&sc[i][j]);
    scanf("%s",o);
    scanf("%d",&p);
    
    for(i=0;i<n;i++) {
        if(o[i] == 'N') continue;
        sum++;
        hap += (1 << i);
    }
    if(sum >= p) {
        printf("0\n");
        return 0;
    }
    if(sum == 0) {
        printf("-1\n");
        return 0;
    }
    dp[hap] = 0;
    for(k=sum+1;k<=n;k++) dfs(n, dp, 0, k - 1, 0);
    for(i=(1<<n)-1;i>=0;i--) {
        int tmp = i;
        int cnt = 0;
        while(tmp) {
            cnt += (tmp & 1);
            tmp >>= 1;
        }
        if(cnt >= p)
            if(dp[i] != -1 && ans > dp[i]) ans = dp[i];
    }
    printf("%d\n",ans);
    return 0;
}