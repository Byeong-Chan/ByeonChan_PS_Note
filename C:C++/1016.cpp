#include <cstdio>
#include <cmath>
bool chk[1000010];
int main() {
    int i, k;
    int ans = 0;
    long long j, n, m, d;
    long long st;
    scanf("%lld %lld",&n,&m);
    k = (int)sqrt(m) + 1;
    for(i=2;i<=k;i++) {
        d = (long long)i*i;
        st = (n / d) * d;
        if (n%d != 0) st += d;
        for(j=st;j<=m;j+=d) chk[(int)(j-n)] = true;
    }
    for(i=0;i<(int)(m-n+1);i++) {
        if(chk[i]) continue;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}