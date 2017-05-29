#include <cstdio>
int main() {
    int i, n;
    int x;
    int min1 = 0x7fffffff;
    int ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        if (x - min1 > ans) ans = x - min1;
        if (x < min1) min1 = x;
    }
    printf("%d",ans);
    return 0;
}