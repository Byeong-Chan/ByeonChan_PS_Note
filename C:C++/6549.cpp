#include <cstdio>
struct bung {
    int x;
    int y;
}stk[100010];
int main() {
    int i, n;
    int top = 0;
    int x;
    int savi;
    long long tmp, ans = 0;
    while(1) {
        top = 0;
        scanf ("%d",&n);
        if (n == 0) break;
        stk[top].x = 0;
        stk[top].y = 0x7fffffff;
        top++;
        ans = 0;
        for (i=0;i<=n;i++) {
            if (i != n) scanf("%d",&x);
            else x = 0;
        
            if (ans < x) ans = x;
            savi = i;
            while(top > 0 && stk[top-1].y >= x) {
                top--;
                tmp = (long long)stk[top].y * (i - (savi = stk[top].x));
                if (tmp > ans) ans = tmp;
            }
            stk[top].x = savi;
            stk[top].y = x;
            top++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}