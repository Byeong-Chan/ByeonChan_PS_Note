#include <cstdio>
int o[12];
int main() {
    int ans = 0;
    int n, m;
    int i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    for(i=n-1;i>=0;i--) {
        ans += m/o[i];
        m %= o[i];
    }
    printf("%d\n",ans);
    return 0;
}