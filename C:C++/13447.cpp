#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct MaxMatchingEdmonds {
    int lca(int match[], int base[], int p[], int a, int b) {
        bool used[n];
        fill(used, used + n, 0);
        while (true) {
            a = base[a];
            used[a] = true;
            if (match[a] == -1) break;
            a = p[match[a]];
        }
        while (true) {
            b = base[b];
            if (used[b]) return b;
            b = p[match[b]];
        }
    }
    
    void markPath(int match[], int base[], bool blossom[], int p[], int v, int b, int children) {
        for (; base[v] != b; v = p[match[v]]) {
            blossom[base[v]] = blossom[base[match[v]]] = true;
            p[v] = children;
            children = match[v];
        }
    }
    
    int findPath(vector<int> graph[], int match[], int p[], int root) {
        bool used[n];
        fill(used, used + n, 0);
        fill(p, p + n, -1);
        int base[n];
        for (int i = 0; i < n; ++i)
            base[i] = i;
        
        used[root] = true;
        int qh = 0;
        int qt = 0;
        int q[n];
        fill(q, q + n, 0);
        q[qt++] = root;
        while (qh < qt) {
            int v = q[qh++];
            
            for (int to : graph[v]) {
                if (base[v] == base[to] || match[v] == to) continue;
                if (to == root || (match[to] != -1 && p[match[to]] != -1)) {
                    int curbase = lca(match, base, p, v, to);
                    bool blossom[n];
                    fill(blossom, blossom + n, 0);
                    markPath(match, base, blossom, p, v, curbase, to);
                    markPath(match, base, blossom, p, to, curbase, v);
                    for (int i = 0; i < n; ++i)
                        if (blossom[base[i]]) {
                            base[i] = curbase;
                            if (!used[i]) {
                                used[i] = true;
                                q[qt++] = i;
                            }
                        }
                } else if (p[to] == -1) {
                    p[to] = v;
                    if (match[to] == -1)
                        return to;
                    to = match[to];
                    used[to] = true;
                    q[qt++] = to;
                }
            }
        }
        return -1;
    }
    
    int maxMatching(vector<int> graph[]) {
        int match[n];
        fill(match, match + n, -1);
        int p[n];
        fill(p, p + n, 0);
        for (int i = 0; i < n; ++i) {
            if (match[i] == -1) {
                int v = findPath(graph, match, p, i);
                while (v != -1) {
                    int pv = p[v];
                    int ppv = match[pv];
                    match[v] = pv;
                    match[pv] = v;
                    v = ppv;
                }
            }
        }
        
        int matches = 0;
        for (int i = 0; i < n; ++i)
            if (match[i] != -1)
                ++matches;
        return matches / 2;
    }
};

// Usage example
bool chk[110][110];
int main() {
    int i, m;
    int x, y;
    vector<int> g[110];
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        if (x > y) swap(x, y);
        if (chk[x][y]) continue;
        chk[x][y] = true;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    
    MaxMatchingEdmonds mme;
    if (n & 1) printf("0\n");
    else printf("%d\n",(n >> 1) == mme.maxMatching(g));
    return 0;
}