#include <cstdio>
long long basis[64];
int main() {
    int i, j, n;
    long long ans = 0, x;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%lld",&x);
        for(j=59;j>=0;j--) {
            if((x >> j) & 1) {
                if(basis[j] == 0) {
                    basis[j] = x;
                    break;
                }
                else x ^= basis[j];
            }
        }
    }
    for(i=59;i>=0;i--) if(ans < (ans ^ basis[i])) ans ^= basis[i];
    printf("%lld\n",ans);
    return 0;
}