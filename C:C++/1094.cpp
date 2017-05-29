#include <stdio.h>
int main() {
    int m;
    int ans = 0;
    scanf("%d",&m);
    while(m > 0) {
        ans += m & 1;
        m >>= 1;
    }
    printf("%d",ans);
    return 0;
}