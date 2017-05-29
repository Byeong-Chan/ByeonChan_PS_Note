#include <cstdio>
#include <algorithm>
using namespace std;

int N, Rank[1010], parent[1010];

void init(int n) {
    N = n;
    for(int i = 1; i <= N; i++) Rank[i] = 1, parent[i] = i;
}

int find(int p) {
    if(parent[p] == p) return p;
    else return find(parent[p]);
}

void uni(int p, int q) {
    p = find(p);
    q = find(q);
    if(Rank[p] > Rank[q]) parent[q] = p;
    else if(Rank[p] < Rank[q]) parent[p] = q;
    else parent[q] = p, Rank[p]++;
}

struct node {
    int x;
    int y;
    int val;
    bool operator< (const node &a) const {
        return val < a.val;
    }
}edge[100010];

int main() {
    int i;
    int n, m;
    long long ans = 0;
    scanf("%d%d",&n,&m);
    init(n);
    for(i=0;i<m;i++) scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].val);
    sort(edge, edge+m);
    for(i=0;i<m;i++) {
        if(find(edge[i].x) == find(edge[i].y)) continue;
        ans += edge[i].val;
        uni(edge[i].x, edge[i].y);
    }
    printf("%lld\n",ans);
    return 0;
}