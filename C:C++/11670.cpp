// Hopcroft-Karp Algorithm O(N sqrt(N))

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], pre[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];
map<long long ,int> tr;
long long  num[10010];

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

long long o[2510][2];
map<long long, bool> chk;
int main() {
    int i, n;
    int pp;
    int cnt = 0;
    long long tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%lld %lld",o[i], o[i]+1);
        tmp = o[i][0] + o[i][1];
        if (tr.find(tmp) == tr.end()) {
            num[cnt] = tmp;
            tr[tmp] = cnt++;
        }
        
        tmp = o[i][0] * o[i][1];
        if (tr.find(tmp) == tr.end()) {
            num[cnt] = tmp;
            tr[tmp] = cnt++;
        }
        
        tmp = o[i][0] - o[i][1];
        if (tr.find(tmp) == tr.end()) {
            num[cnt] = tmp;
            tr[tmp] = cnt++;
        }
    }
    init(cnt, n);
    for(i=0;i<n;i++) {
        tmp = o[i][0] + o[i][1];
        if (chk.find(tmp) == chk.end()) addEdge(tr[tmp], i);
        chk[tmp] = true;
        
        tmp = o[i][0] * o[i][1];
        if (chk.find(tmp) == chk.end()) addEdge(tr[tmp], i);
        chk[tmp] = true;
        
        tmp = o[i][0] - o[i][1];
        if (chk.find(tmp) == chk.end()) addEdge(tr[tmp], i);
        chk[tmp] = true;
        
        chk.clear();
    }
    if (maxMatching() < n) printf("impossible\n");
    else {
        for(i=0;i<n;i++) {
            pp = matching[i];
            if (o[i][0] + o[i][1] == num[pp]) printf("%lld + %lld = %lld\n",o[i][0], o[i][1], num[pp]);
            else if (o[i][0] * o[i][1] == num[pp]) printf("%lld * %lld = %lld\n",o[i][0], o[i][1], num[pp]);
            else if (o[i][0] - o[i][1] == num[pp]) printf("%lld - %lld = %lld\n",o[i][0], o[i][1], num[pp]);
        }
    }
    return 0;
}