#include <cstdio>
int lose[1010], win[1010];
int main() {
    int i, n, m;
    int pita;
    int min1, max1;
    int t;
    int x, y, a, b;
    for(scanf("%d",&t);t--;) {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++) {
            scanf("%d %d %d %d",&x,&y,&a,&b);
            lose[x] += b;
            win[x] += a;
            lose[y] += a;
            win[y] += b;
        }
        min1 = 1000;
        max1 = 0.0;
        for(i=1;i<=n;i++) {
            if (win[i] == 0 && lose[i] == 0) pita = 0.0;
            else pita = (int)(((long long)win[i] * win[i] * 1000) / (long double)(win[i] * win[i] + lose[i] * lose[i]));
            if (pita > max1) max1 = pita;
            if (pita < min1) min1 = pita;
            lose[i] = win[i] = 0;
        }
        printf("%d\n%d\n",max1, min1);
    }
    return 0;
}