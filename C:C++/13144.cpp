#include <cstdio>
int chk[100010];
int main() {
    int i, n;
    int k = 1;
    int x;
    long long ans = 0;
    int max1 = 0;
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf("%d",&x);
        if (max1 < chk[x]) max1 = chk[x];
        chk[x] = i;
        ans += i - max1;
    }
    printf("%lld\n",ans);
    return 0;
}