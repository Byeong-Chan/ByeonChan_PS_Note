#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int o[210][210];
int ans[210];
int n1, n2, edges, last[MAXN1], pre[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

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
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
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

void trace (int v) {
    printf("%d ",matching[v]+1);
}

int main() {
    int i, j, n, m;
    int q, x, y, v;
    scanf("%d %d",&n, &m);
    init(n, n);
    for(i=0;i<m;i++) {
        scanf("%d %d %d %d", &q, &x, &y, &v);
        if (q == 1) {
            o[v][1]++;
            o[v][x]--;
            o[v][y+1]++;
            o[v][n+1]--;
            for(j=v+1;j<=n;j++) {
                o[j][x]++;
                o[j][y+1]--;
            }
        }
        else {
            o[v][1]++;
            o[v][x]--;
            o[v][y+1]++;
            o[v][n+1]--;
            for(j=v-1;j>=1;j--) {
                o[j][x]++;
                o[j][y+1]--;
            }
        }
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            o[i][j] += o[i][j-1];
            if (!o[i][j]) addEdge(i-1, j-1);
        }
    }
    if (maxMatching() < n) printf("-1");
    else for(i=0;i<n;i++) trace(i);
    return 0;
}