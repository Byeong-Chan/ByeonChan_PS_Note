#include <cstdio>
int parents[1000001];
int find(int x) {
    if(x == parents[x]) return x;
    else return parents[x] = find(parents[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parents[y] = x;
}
int main() {
    int q, a, b;
    int n, m;
    scanf("%d %d",&n, &m);
    for(int i=1;i<=n;i++) parents[i] = i;
    for(int i=0;i<m;i++) {
        scanf("%d %d %d",&q,&a,&b);
        if(q == 0) uni(a, b);
        else if(find(a) == find(b)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}