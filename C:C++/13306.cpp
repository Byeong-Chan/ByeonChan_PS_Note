#include <cstdio>
int parents[200010];
int Rank[200010];
int cnt[200010];
int moth[200010];
int ans[200010];
int find(int x) {
    if(x == parents[x]) return x;
    else return parents[x] = find(parents[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if(Rank[x] == Rank[y]) parents[y] = x, Rank[x]++;
    else if(Rank[x] < Rank[y]) parents[x] = y;
    else parents[y] = x;
}
struct node {
    int q;
    int x;
    int y;
}u[400010];
int main() {
    int i, n, Q, m = 0;
    scanf("%d %d",&n,&Q);
    parents[1] = 1;
    for(i=2;i<=n;i++) {
        scanf("%d",&moth[i]);
        parents[i] = i;
    }
    Q += n - 1;
    for(i=0;i<Q;i++) {
        scanf("%d %d", &u[i].q, &u[i].x);
        if(u[i].q == 0) cnt[u[i].x]++;
        else scanf("%d",&u[i].y);
    }
    for(i=2;i<=n;i++) {
        if(cnt[i]) continue;
        uni(i, moth[i]);
    }
    for(i=Q-1;i>=0;i--) {
        if(u[i].q == 0) {
            if(!(--cnt[u[i].x])) uni(u[i].x, moth[u[i].x]);
            continue;
        }
        if(find(u[i].x) == find(u[i].y)) ans[m++] = 1;
        else ans[m++] = 0;
    }
    for(i=m-1;i>=0;i--) printf("%s\n",ans[i] ? "YES" : "NO");
    return 0;
}