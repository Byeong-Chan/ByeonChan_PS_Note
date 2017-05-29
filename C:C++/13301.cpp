#include <cstdio>
int main() {
    int n;
    int i;
    long long x = 1, y = 1, t;
    scanf("%d",&n);
    for(i=1;i<n;i++) {
        t = y;
        y = x + y;
        x = t;
    }
    printf("%lld\n",(x+y) << 1);
    return 0;
}