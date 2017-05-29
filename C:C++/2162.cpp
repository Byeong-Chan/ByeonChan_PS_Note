#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 3010;

struct bung {
    int x1;
    int y1;
    int x2;
    int y2;
}o[MAXN];

int parent[MAXN], size[MAXN], Rank[MAXN];
int cnt[MAXN];

int ccw(ll x1, ll y1, ll x2, ll y2, ll a, ll b) {
    ll d1 = x1*y2 + x2*b + a*y1;
    ll d2 = x2*y1 + a*y2 + x1*b;
    if(d1 - d2 < 0) return -1; // 시계
    else if(d1 - d2 > 0) return 1; // 반시계
    return 0;
}

void init(int n){
    for (int i=1; i<= n; i++) {
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
int main() {
    int i, j, n;
    int tmp1, tmp2;
    int ans = 0;
    int sum = 0;
    scanf("%d",&n);
    init(n);
    for(i=1;i<=n;i++) {
        scanf("%d %d %d %d",&o[i].x1,&o[i].y1,&o[i].x2,&o[i].y2);
        if(o[i].x1 > o[i].x2) {
            swap(o[i].x1, o[i].x2);
            swap(o[i].y1, o[i].y2);
        }
        if(o[i].x1 == o[i].x2) {
            if(o[i].y1 > o[i].y2) {
                swap(o[i].x1, o[i].x2);
                swap(o[i].y1, o[i].y2);
            }
        }
    }
    for(i=1;i<=n;i++) {
        for(j=i+1;j<=n;j++) {
            tmp1 = ccw(o[i].x1, o[i].y1, o[i].x2, o[i].y2, o[j].x1, o[j].y1) * ccw(o[i].x1, o[i].y1, o[i].x2, o[i].y2, o[j].x2, o[j].y2);
            tmp2 = ccw(o[j].x1, o[j].y1, o[j].x2, o[j].y2, o[i].x1, o[i].y1) * ccw(o[j].x1, o[j].y1, o[j].x2, o[j].y2, o[i].x2, o[i].y2);
            if(tmp1 <= 0 && tmp2 <= 0) {
                if(tmp1 == 0 && tmp2 == 0) {
                    if(o[i].x1 == o[i].x2) {
                        if(o[i].y1 <= o[j].y1 && o[i].y2 >= o[j].y1) uni(i, j);
                        else if(o[i].y1 <= o[j].y2 && o[i].y2 >= o[j].y2) uni(i, j);
                        else if(o[j].y1 <= o[i].y1 && o[j].y2 >= o[i].y1) uni(i, j);
                        else if(o[j].y1 <= o[i].y2 && o[j].y2 >= o[i].y2) uni(i, j);
                        continue;
                    }
                    if(o[i].x1 <= o[j].x1 && o[i].x2 >= o[j].x1) uni(i, j);
                    else if(o[i].x1 <= o[j].x2 && o[i].x2 >= o[j].x2) uni(i, j);
                    else if(o[j].x1 <= o[i].x1 && o[j].x2 >= o[i].x1) uni(i, j);
                    else if(o[j].x1 <= o[i].x2 && o[j].x2 >= o[i].x2) uni(i, j);
                }
                else uni(i, j);
            }
        }
    }
    for(i=1;i<=n;i++) {
        tmp1 = find(i);
        if(!cnt[tmp1]) sum++;
        
        cnt[tmp1]++;
        if(cnt[tmp1] > ans) ans = cnt[tmp1];
    }
    printf("%d\n%d\n",sum,ans);
    return 0;
}