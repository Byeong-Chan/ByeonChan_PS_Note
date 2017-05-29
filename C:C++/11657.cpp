#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

struct info {
    int u;
    int v;
    int val;
    info() {}
    info(int iu, int iv, int ival) {
        u = iu;
        v = iv;
        val = ival;
    }
};
vector<info> edge;
int d[510];
int main() {
    int i, j, n, m;
    int x, y, z;
    scanf("%d %d",&n,&m);
    edge.resize(m);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        edge[i] = info(x, y, z);
    }
    fill(d+1, d+n+1, INF);
    bool flag;
    d[1] = 0;
    for(i=0;i<n;i++) {
        flag = false;
        for(j=0;j<m;j++) {
            info &e = edge[j];
            if (d[e.u] == INF) continue;
            if (d[e.u] + e.val < d[e.v]) {
                flag = true;
                d[e.v] = d[e.u] + e.val;
            }
        }
        if(!flag) break;
        if(i == n - 1 && flag) {
            printf("-1\n");
            return 0;
        }
    }
    for(i=2;i<=n;i++) {
        if(d[i] == INF) printf("-1\n");
        else printf("%d\n",d[i]);
    }
    return 0;
}