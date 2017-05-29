#include <cstdio>
int bridge[110];
int main() {
    int i, j, n, x;
    int now = 0;
    int l, w;
    int ans = 1;
    scanf("%d",&n);
    scanf("%d %d",&l,&w);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        if (bridge[1] != 0) {
            ans++;
            for(j=l+1;j>=2;j--) {
                bridge[j] = bridge[j-1];
                bridge[j-1] = 0;
            }
            now += bridge[1];
            now -= bridge[l+1];
        }
        while(now + x > w) {
            ans++;
            for(j=l+1;j>=2;j--) {
                bridge[j] = bridge[j-1];
                bridge[j-1] = 0;
            }
            now -= bridge[l+1];
        }
        now += x;
        bridge[1] = x;
    }
    ans += l;
    printf("%d\n",ans);
    return 0;
}