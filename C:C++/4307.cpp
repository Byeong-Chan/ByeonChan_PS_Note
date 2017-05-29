#include <cstdio>
int main() {
    int i, n, m;
    int x;
    int ans1 = 0, ans2 = 0;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&m,&n);
        ans1 = ans2 = 0;
        for(i=0;i<n;i++) {
            scanf("%d",&x);
            if (x > ans2) ans2 = x;
            if (m-x > ans2) ans2 = m-x;
            
            if (x < m-x && ans1 < x) ans1 = x;
            if (x >= m-x && ans1 < m-x) ans1 = m-x;
        }
        printf("%d %d\n",ans1, ans2);
    }
    return 0;
}