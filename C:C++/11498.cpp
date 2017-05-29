#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> phnode[300010];
int ph = 0;
int node[300010];
int num[300010];
int low[300010];
int range[300010];
bool chk[300010];
bool visit[300010];
int cnt = 0;
int group[300010];
int moth[300010];
int pre[300010];
vector<int> edge[300010];
vector<int> trace;
void dfs(int u, bool sw) {
    chk[u] = true;
    low[u] = ++cnt;
    num[u] = cnt;
    range[u] = cnt;
    group[u] = sw;
    bool isroot = true;
    trace.push_back(u);
    
    for(int i=0;i<edge[u].size();i++) {
        int v = edge[u][i];
        if (!chk[v]) {
            moth[v] = u;
            dfs(v, !sw);
        }
        if (range[u] < range[v]) range[u] = range[v];
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
        dfs(i, false);
    }
}
void bfs(int a, int b) {
    int u, v;
    int i;
    int tmp;
    visit[a] = true;
    queue<int> que;
    vector<int> ans;
    que.push(a);
    while(1) {
        u = que.front();
        que.pop();
        if (range[u] >= num[b] && num[u] <= num[b]) {
            tmp = u;
            break;
        }
        
        for(i=0;i<edge[u].size();i++) {
            v = edge[u][i];
            if (visit[v]) continue;
            if (node[b] != node[v]) continue;
            if (group[u] == group[v]) continue;
            que.push(v);
            pre[v] = u;
        }
    }
    
    int d = b;
    ans.push_back(d);
    while (1) {
        if(moth[d] == 0) break;
        d = moth[d];
        ans.push_back(d);
        if (d == tmp) break;
    }
    
    while (1) {
        if(pre[tmp] == 0) break;
        tmp = pre[tmp];
        ans.push_back(tmp);
        if (tmp == a) break;
    }
    printf("1\n%d\n",(int)ans.size());
    while(ans.size()) {
        printf("%d\n",ans.back());
        ans.pop_back();
    }
}
void clear(int n) {
    int i;
    trace.clear();
    cnt = 0;
    ph = 0;
    for(i=1;i<=n;i++) {
        low[i] = num[i] = node[i] = range[i] = chk[i] = visit[i] = group[i] = moth[i] = pre[i] = 0;
        edge[i].clear();
        phnode[i].clear();
    }
}
int main() {
    int i, j, n, m;
    int x, y;
    int k;
    int pos, nxt;
    bool sw;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++) {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
        }
        
        scc(n);
        
        sw = false;
        for (i=1;i<=ph;i++) {
            for (j=0;j<phnode[i].size();j++) {
                pos = phnode[i][j];
                for(k=0;k<edge[pos].size();k++) {
                    nxt = edge[pos][k];
                    if (node[nxt] != i) continue;
                    if (group[pos] == group[nxt]) {
                        if(range[nxt] >= num[pos] && num[nxt] <= num[pos]) {
                            visit[pos] = true;
                            bfs(nxt, pos);
                            sw = true;
                            break;
                        }
                    }
                }
                if (sw) break;
            }
            if (sw) break;
            for (j=0;j<phnode[i].size();j++) {
                pos = phnode[i][j];
                for(k=0;k<edge[pos].size();k++) {
                    nxt = edge[pos][k];
                    if (node[nxt] != i) continue;
                    if (group[pos] == group[nxt]) {
                        if(range[nxt] < num[pos] || num[nxt] > num[pos]) {
                            visit[pos] = true;
                            bfs(nxt, pos);
                            sw = true;
                            break;
                        }
                    }
                }
                if (sw) break;
            }
            if (sw) break;
        }
        clear(n);
        if(!sw) printf("-1\n");
    }
    return 0;
}