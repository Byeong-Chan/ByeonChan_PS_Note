#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int p[10010];
int k[10010];
int dx[10010];
int dy[10010];
int fx[10010];
int fy[10010];
struct node {
    int x1;
    int y1;
    int x2;
    int y2;
}o[5010];
map<int, int> tx, ty;
vector<int> Q[10010];
bool chk[10010];
int use[10010];
long long ans[10010];
long long ph[10010];
int parent[10010], size[10010], Rank[10010];

void init(){
    for (int i=1; i<=10000; i++) {
        parent[i] = i;
        size[i] = 1;
        Rank[i] = 0;
    }
}

int find(int p){
    if(parent[p] == p) return p;
    else return parent[p] = find(parent[p]);
}

void uni(int p, int q){
    p = find(p);
    q = find(q);
    if(Rank[p] < Rank[q]) parent[p] = q, size[q] += size[p];
    else parent[q] = p, size[p] += size[q];;
    if(Rank[p] == Rank[q]) Rank[p]++;
}

int stor[10010];
void union_find(int x, int last, int pos, int cmp) {
    int nxt;
    int sav;
    int sz = 0;
    
    while(1) {
        if (use[x] != cmp) {
            use[x] = cmp;
            ph[pos] += (fx[x+1] - fx[x]);
        }
        nxt = p[x];
        if (nxt >= last) break;
        stor[sz++] = x;
        x = nxt;
    }
    sav = nxt;
    
    while(sz--) {
        nxt = stor[sz];
        p[nxt] = sav;
        uni(x, nxt);
    }
}
int main() {
    int i, j, n;
    int e = 0;
    int maxx = 0, maxy = 0;
    int tmp;
    long long h;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d %d %d %d",&o[i].x1,&o[i].y1, &o[i].x2,&o[i].y2);
        dx[e] = o[i].x1;
        dy[e] = o[i].y1;
        e++;
        dx[e] = o[i].x2;
        dy[e] = o[i].y2;
        e++;
    }
    sort(dx, dx+e);
    sort(dy, dy+e);
    for(i=0;i<e;i++) {
        if(tx[dx[i]] == 0) {
            tx[dx[i]] = ++maxx;
            fx[maxx] = dx[i];
        }
        if(ty[dy[i]] == 0) {
            ty[dy[i]] = ++maxy;
            fy[maxy] = dy[i];
        }
    }
    for(i=1;i<=n;i++) {
        o[i].x1 = tx[o[i].x1];
        o[i].x2 = tx[o[i].x2];
        o[i].y1 = ty[o[i].y1];
        o[i].y2 = ty[o[i].y2];
        Q[o[i].y1].push_back(i);
        Q[o[i].y2].push_back(i);
    }
    for(i=1;i<maxy;i++) {
        h = fy[i+1] - fy[i];
        for(j=maxx;j>=0;j--) {
            p[j] = j+1;
            if (Q[i].size() != 0) ph[j] = 0;
        }
        
        if (Q[i].size() != 0) {
            init();
            while(Q[i].size()) {
                tmp = Q[i].back();
                chk[tmp] = !chk[tmp];
                Q[i].pop_back();
            }
            for(j=n;j>=0;j--) if(chk[j]) union_find(o[j].x1, o[j].x2, j, i);
        }
        for(j=n;j>=0;j--) if(ph[j]) ans[j] += ph[j] * h;
    }
    for(i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}