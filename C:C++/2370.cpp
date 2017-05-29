#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10010;
int parent[MAXN << 1], Rank[MAXN << 1];
int nxt[MAXN << 1];
int dx[MAXN << 1];
bool chk[MAXN << 1];

void init(int n) {
    for(int i=1;i<=n;i++) {
        parent[i] = i;
        nxt[i] = i+1;
        Rank[i] = 0;
    }
    nxt[n+1] = n+1;
    parent[n+1] = n+1;
}

int findd(int p) {
    if(parent[p] == p) return p;
    else return parent[p] = findd(parent[p]);
}

void uni(int p, int q) {
    p = findd(p);
    q = findd(q);
    if(Rank[p] == Rank[q]) parent[q] = p, Rank[p]++;
    else if(Rank[p] > Rank[q]) parent[q] = p;
    else parent[p] = q;
}

int compress(int x, int n) {
    int st = 0;
    int ed = n-1;
    int mid;
    while(st < ed) {
        mid = (st + ed) >> 1;
        if(dx[mid] < x) st = mid + 1;
        else ed = mid;
    }
    return st + 1;
}

struct post {
    int x;
    int y;
    post() {}
    post(int ix, int iy) {
        x = ix;
        y = iy;
    }
}o[MAXN];

int main() {
    int i;
    int n, m;
    int x, y;
    int tmp, p;
    int ans = 0;
    bool judge;
    scanf("%d",&n);
    m = n << 1;
    for(i=0;i<n;i++) {
        scanf("%d %d",&o[i].x,&o[i].y);
        
        o[i].y++;
        
        dx[i*2] = o[i].x;
        dx[i*2+1] = o[i].y;
    }
    sort(dx, dx+m);
    m = (int)(unique(dx, dx+m) - dx);
    init(m);
    for(i=n-1;i>=0;i--) {
        x = compress(o[i].x, m);
        y = compress(o[i].y, m);
        judge = false;
        while(1) {
            x = findd(x);
            if(!chk[x]) judge = true;
            chk[x] = true;
            
            p = findd(nxt[x]);
            if(p >= y) break;
            if(!chk[p]) judge = true;
            chk[p] = true;
            
            tmp = nxt[p];
            uni(x, p);
            nxt[findd(x)] = tmp;
        }
        ans += judge ? 1 : 0;
    }
    printf("%d\n",ans);
    return 0;
}