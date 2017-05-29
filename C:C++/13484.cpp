#include <cstdio>
int main() {
    int i, j, n, x;
    int ans;
    scanf("%d",&x);
    scanf("%d",&n);
    ans = x*(n+1);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        ans -= x;
    }
    printf("%d\n",ans);
    return 0;
}