#include <cstdio>
int main() {
    int n, m;
    int i, j;
    int d;
    int cnt;
    int t;
    scanf("%d",&t);
    while(t--) {
        long long ans = 2;
        long long p;
        scanf("%d %d",&n,&m);
        for(i=n;i<=m;i++) {
            d = i;
            p = 1;
            for(j=2;j*j<=i;j++) {
                cnt = 1;
                while (d % j == 0) {
                    cnt++;
                    d /= j;
                }
                p *= cnt;
            }
            if (d > 1) p *= 2;
            if(ans < p) ans = p;
        }
        printf("%lld\n",ans);
    }
    return 0;
}