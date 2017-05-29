#include <stdio.h>
int main() {
    int n, x;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        if(i == x) break;
    }
    if(i == n+1) printf("1000000007");
    else printf("-1");
    return 0;
}