#include <cstdio>
#include <cmath>
int main() {
    int t;
    int x, y;
    int m, n;
    int ans;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&x,&y);
        m = y - x;
        n = (int)sqrt(m);
        m -= n*n;
        ans = 2*n - 1;
        
        if (m > 0) {
            if (m <= n) ans++;
            else ans+=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}