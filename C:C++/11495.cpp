#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2610;
const int INF = 0x7fffffff;
 
struct edge {
    int a, b, cap, flow;
};
 
int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
int ans[MAXN];
bool chk[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}
 
bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    for(int i=0;i<N;i++) d[i] = -1;
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
            to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}
 
int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
        to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
 
int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        for(int i=0;i<N;i++) ptr[i] = 0;
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}
 
void clear() {
    for(int i=0;i<MAXN;i++) g[i].clear();
    e.clear();
}

int o[54][54];
bool chok[54][54];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0,0,1,-1};

void trace(int v, int m) {
	int x, y;
    for (size_t l=0; l<g[v].size(); ++l) {
        int id = g[v][l];
        int to = e[id].b;
        int f = e[id].flow;

        // Please trace flow here
		if (f > 0) {
			x = (v-1) / m;
			y = (v-1) % m;
			o[x][y] -= f;

			x = (to-1) / m;
			y = (to-1) % m;
			o[x][y] -= f;
		}
    }
}

int main() {
	int T;
	int n, m;
	int i, j, k;
	int x, y;
	int tmp, nxt;
	int ans;
	for(scanf("%d",&T);T>0;T--) {
		scanf("%d %d",&n,&m);
		k = 0;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				chok[i+1][j] = !chok[i][j];
				chok[i][j+1] = !chok[i][j];
				scanf("%d",&o[i][j]);
			}
		}
		N = n * m + 2;
		s = 0;
		t = n * m + 1;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(chok[i][j]) {
					tmp = m * i + j + 1;
					add_edge(s, tmp, o[i][j]);
					for(k=0;k<4;k++) {
						x = i + dx[k];
						y = j + dy[k];
						if (x < 0 || x >= n || y < 0 || y >= m) continue;
						nxt = m * x + y + 1;
						add_edge(tmp, nxt, o[i][j]);
					}
				}
				else {
					tmp = m * i + j + 1;
					add_edge(tmp, t, o[i][j]);
				}
			}
		}
		ans = dinic();
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if (chok[i][j]) {
					tmp = m * i + j + 1;
					trace(tmp, m);
				}
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(o[i][j] > 0) ans += o[i][j];
			}
		}
		printf("%d\n",ans);
		clear();
	}
    return 0;
}