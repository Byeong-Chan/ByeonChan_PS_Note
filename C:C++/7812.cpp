#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edge[10010], val[10010];
bool chk[10010];
int cnt[10010];
long long dp[10010];
long long dp2[10010];
int n;
void dfs(int u) {
    chk[u] = true;
    long long ans = (long long)0x7fffffff << 20;
    for(int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if(chk[v]) continue;
        dfs(v);
        if(ans > dp2[v] + (n - 2 * cnt[v]) * val[u][i]) ans = dp2[v] + (n - 2 * cnt[v]) * val[u][i];
        dp[u] += dp[v];
        dp[u] += cnt[v] * val[u][i];
        cnt[u] += cnt[v];
    }
    if(ans < 0) dp2[u] = ans;
    else dp2[u] = 0;
}
int main() {
    int i;
    int x, y, z;
    while(1) {
        scanf("%d",&n);
        if(n == 0) break;
        for(i=0;i<n;i++) chk[i] = false, cnt[i] = 1, dp[i] = dp2[i] = 0;
        for(i=0;i<n-1;i++) {
            scanf("%d %d %d",&x,&y,&z);
            edge[x].push_back(y);
            edge[y].push_back(x);
            val[x].push_back(z);
            val[y].push_back(z);
        }
        
        dfs(0);
        printf("%lld\n",dp[0] + dp2[0]);
        
        for(i=0;i<n;i++) edge[i].clear(), val[i].clear();
    }
    return 0;
}