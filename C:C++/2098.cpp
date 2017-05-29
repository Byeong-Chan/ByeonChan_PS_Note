#include <cstdio>
int dp[1<<16][16];
int con[16][16];
int n;
bool chk[1<<16][16];
int dfs(int pos, int here) {
    if(chk[pos][here]) return dp[pos][here];
    int ans = 987654321;
    
    for(int i = 0; i < n; i++) {
        if(con[here][i] == 0) continue;
        if((pos & (1 << i)) == 0) continue;
        int tmp = dfs(pos ^ (1 << i), i) + con[here][i];
        if(ans > tmp) ans = tmp;
    }
    
    chk[pos][here] = true;
    return dp[pos][here] = ans;
}
int main() {
    int i, j;
    int ans = 0x7fffffff;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&con[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        dp[0][i] = 987654321;
        chk[0][i] = true;
    }
    dp[0][0] = 0;
    int tmp = dfs((1<<n)-1, 0);
    if(ans > tmp) ans = tmp;
    
    printf("%d\n",ans);
    return 0;
}