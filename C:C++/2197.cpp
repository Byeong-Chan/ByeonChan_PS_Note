#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> con[152];
int dt[152][152], tmp[152];
int moth[152];
int son[152];
bool chk[152];
queue<int> q;
void dfs(int u) {
    int i;
    int v;
    int cnt = 0;
    chk[u] = true;
    for (i=0;i<con[u].size();i++) {
        v = con[u][i];
        if (chk[v]) continue;
        moth[v] = u;
        cnt++;
        dfs(v);
    }
    son[u] = cnt;
    if(moth[u] != -1) dt[u][1] = cnt - 1;
    else dt[u][1] = cnt;
}
int main() {
    int i, j, k, n, m;
    int x, y;
    int ans = 0x7fffffff;
    int now, nxt;
    scanf("%d %d",&n,&m);
    for(i=0;i<n-1;i++) {
        scanf("%d %d",&x,&y);
        con[x].push_back(y);
        con[y].push_back(x);
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            dt[j][0] = 0;
            for (k=1;k<=m;k++) dt[j][k] = 0x7fffffff;
            moth[j] = 0;
            chk[j] = false;
        }
        moth[i] = -1;
        dfs(i);
        
        for(j=1;j<=n;j++) if(son[j] == 0) q.push(j);
        
        while (q.size()) {
            now = q.front();
            q.pop();
            nxt = moth[now];
            if (nxt == -1) break;
            
            if (--son[nxt] == 0) q.push(nxt);
            
            for(j=1;j<=m;j++) {
                tmp[j] = dt[nxt][j];
                dt[nxt][j] = 0x7fffffff;
            }
            for (j=1;j<=m;j++) {
                if (tmp[j] == 0x7fffffff) continue;
                for (k=0;k<=m-j;k++) {
                    if (dt[now][k] == 0x7fffffff) continue;
                    dt[nxt][j+k] = min(dt[nxt][j+k], dt[now][k] + tmp[j]);
                }
            }
        }
        
        if (dt[i][m] < ans) ans = dt[i][m];
    }
    printf("%d",ans);
    return 0;
}