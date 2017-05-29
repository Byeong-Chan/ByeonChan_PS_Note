#include <cstdio>
int main() {
    int i, n;
    int d;
    int ans = 0;
    int tmp, pp1, pp2;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        tmp = i % 10;
        d = i / 10;
        pp2 = -10000;
        while(d) {
            pp1 = tmp - (d % 10);
            tmp = d % 10;
            if(pp2 == -10000) {d /= 10; pp2 = pp1; continue;}
            if(pp1 != pp2) break;
            d /= 10;
        }
        if(d == 0) ans++;
    }
    printf("%d\n",ans);
    return 0;
}