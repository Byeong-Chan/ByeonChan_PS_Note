#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> edge[10010];
vector<bool> trace[10010][3];
int value[10010];
int dp[10010][2];
int ans[10010], sz = 0;
bool chk[10010];
void dfs(int u) {
    chk[u] = true;
    dp[u][0] = 0;
    dp[u][1] = value[u];
    trace[u][0].resize(edge[u].size());
    trace[u][1].resize(edge[u].size());
    trace[u][2].resize(edge[u].size());
    for(int i = 0; i<edge[u].size();i++) {
        int v = edge[u][i];
        if(chk[v]) continue;
        dfs(v);
        if(dp[v][1] < dp[v][0]) {
            dp[u][0] += dp[v][0];
            trace[u][0][i] = true;
        }
        else {
            dp[u][0] += dp[v][1];
            trace[u][1][i] = true;
        }
        dp[u][1] += dp[v][0];
        trace[u][2][i] = true;
    }
}
void backtrack(int u, bool sw) {
    if(sw) ans[sz++] = u;
    for(int i = 0; i<edge[u].size();i++) {
        int v = edge[u][i];
        if(!sw && trace[u][0][i]) backtrack(v, false);
        if(!sw && trace[u][1][i]) backtrack(v, true);
        if(sw && trace[u][2][i]) backtrack(v, false);
    }
}
int main() {
    int i, n;
    int x, y;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&value[i]);
    for(i=0;i<n-1;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1);
    if(dp[1][0] > dp[1][1]) {
        printf("%d\n",dp[1][0]);
        backtrack(1, false);
    }
    else {
        printf("%d\n",dp[1][1]);
        backtrack(1, true);
    }
    sort(ans, ans+sz);
    for(i=0;i<sz;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}