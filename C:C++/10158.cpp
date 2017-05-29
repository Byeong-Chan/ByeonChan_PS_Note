#include <cstdio>
int dx[80010], dy[80010];
int main() {
    int i;
    int cnt;
    int n, m;
    int p, q;
    int t;
    int k1, k2;
    scanf("%d %d",&n,&m);
    k1 = n * 2;
    k2 = m * 2;
    cnt = 0;
    for(i=0;i<k1;i++) {
        dx[i] = cnt;
        if(i >= n) cnt--;
        else cnt++;
    }
    cnt = 0;
    for(i=0;i<k2;i++) {
        dy[i] = cnt;
        if(i >= m) cnt--;
        else cnt++;
    }
    scanf("%d %d",&p,&q);
    scanf("%d",&t);
    p += t;
    q += t;
    p %= k1;
    q %= k2;
    printf("%d %d\n",dx[p], dy[q]);
    return 0;
}