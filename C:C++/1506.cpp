#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> phnode[110];
int ph = 0;
int node[110];
int num[110];
int low[110];
bool chk[110];
int cst[110];
int cnt = 0;
vector<int> edge[110];
vector<int> trace;
void dfs(int u) {
    chk[u] = true;
    low[u] = ++cnt;
    num[u] = cnt;
    bool isroot = true;
    trace.push_back(u);
    
    for(int i=0;i<edge[u].size();i++) {
        int v = edge[u][i];
        if (!chk[v]) dfs(v);
        if (low[u] > low[v]) {
            low[u] = low[v];
            isroot = false;
        }
    }
    
    if (isroot) {
        ph++;
        while (true) {
            int x = trace.back();
            trace.pop_back();
            node[x] = ph;
            phnode[ph].push_back(x);
            low[x] = 0x7fffffff;
            
            if (x == u) break;
        }
    }
}
void scc(int n) {
    for(int i=1;i<=n;i++) {
        if(chk[i]) continue;
        dfs(i);
    }
}
int main() {
    int i, j;
    int n;
    int x;
    int ans = 0;
    int min1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&cst[i]);
    
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%1d",&x);
            if (i == j) continue;
            if (x) edge[i].push_back(j);
        }
    }
    scc(n);
    
    for (i=1;i<=ph;i++) {
        min1 = cst[phnode[i][0]];
        for(j=1;j<phnode[i].size();j++) min1 = min(cst[phnode[i][j]], min1);
        ans += min1;
    }
    printf("%d\n",ans);
    return 0;
}