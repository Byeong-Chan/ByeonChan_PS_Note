#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], pre[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];
vector<int> odd;
vector<int> even;

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    pre[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = pre[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = pre[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
int o[53];
int judge[53];
int ans[53];
bool chk[2010];
int main() {
    int i, j, k, n;
    int sz = 0;
    int odd = 0, even = 0;
    scanf("%d",&n);
    chk[0] = chk[1] = true;
    for(i=2;i<=2000;i++) {
        if(chk[i]) continue;
        for(j=2*i;j<=2000;j+=i) chk[j] = true;
    }
    for(i=0;i<n;i++) {
        scanf("%d",&o[i]);
        if(o[i] & 1) judge[i] = odd++;
        else judge[i] = even++;
    }
    for(k=1;k<n;k++) {
        if (chk[o[0] + o[k]]) continue;
        init(odd, even);
        for(i=1;i<n;i++) {
            if (i == k) continue;
            for(j=i+1;j<n;j++) {
                if (j == k) continue;
                if(chk[o[i] + o[j]]) continue;
                if(o[i] & 1) addEdge(judge[i], judge[j]);
                else addEdge(judge[j], judge[i]);
            }
        }
        if (maxMatching() == (n >> 1) - 1) ans[sz++] = o[k];
    }
    sort(ans,ans+sz);
    if(sz == 0) printf("-1");
    for(i=0;i<sz;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}