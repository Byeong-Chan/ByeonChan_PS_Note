#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN1 = 1000000;
const int MAXN2 = 1000000;
const int MAXM = 3000000;

int n1, n2, edges, last[MAXN1], pre[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];
char o[140][140];
int u[140][140];
int chk[140][140];
int length[1460][1460];

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

int que[1460][3];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
    int i, j, k, n, m;
    int e = 0;
    int t = 0;
    int st, ed, mid;
    int tmp;
    int qt, qh;
    int x, y, z;
    int tx, ty, tz;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%s",o[i]);
        for(j=0;j<m;j++) {
            if(o[i][j] == '.') u[i][j] = e++;
            if(o[i][j] == 'D') u[i][j] = t++;
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(o[i][j] == 'D') {
                chk[i][j] = tmp = u[i][j] + 1;
                qt = qh = 0;
                que[qt][0] = i;
                que[qt][1] = j;
                que[qt][2] = 0;
                qt++;
                while (qh < qt) {
                    x = que[qh][0];
                    y = que[qh][1];
                    z = que[qh][2];
                    qh++;
                    if(o[x][y] == '.') length[u[x][y]][tmp-1] = z;
                    
                    for(k=0;k<4;k++) {
                        tx = x + dx[k];
                        ty = y + dy[k];
                        tz = z + 1;
                        if (tx >= n || tx < 0 || ty >= m ||ty < 0) continue;
                        if (o[tx][ty] != '.') continue;
                        if (chk[tx][ty] == tmp) continue;
                        que[qt][0] = tx;
                        que[qt][1] = ty;
                        que[qt][2] = tz;
                        qt++;
                        
                        chk[tx][ty] = tmp;
                    }
                }
            }
        }
    }
    st = 1;
    ed = 289;
    while(st < ed) {
        mid = (st+ed) >> 1;
        init(e, t * (mid + 1));
        for(i=0;i<e;i++) {
            for(j=0;j<t;j++) {
                if (length[i][j] == 0) continue;
                for(k=length[i][j];k<=mid;k++) addEdge(i, j * (mid+1) + k);
            }
        }
        if (maxMatching() == e) ed = mid;
        else st = mid + 1;
    }
    if (st < 289) printf("%d\n",st);
    else printf("impossible\n");
    return 0;
}