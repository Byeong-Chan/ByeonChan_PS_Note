#include <stdio.h>
int dt[10];
int tmp[10];
int main() {
    int i, j, k;
    int n;
    int ans = 0;
    for(i=0;i<10;i++) dt[i] = 1;
    scanf("%d",&n);
    for(i=1;i<n;i++) {
        for(j=0;j<10;j++) {
            tmp[j] = dt[j];
            dt[j] = 0;
        }
        for(j=0;j<10;j++) {
            for(k=j;k>=0;k--) {
                dt[j] += tmp[k];
                dt[j] %= 10007;
            }
        }
    }
    for(i=0;i<10;i++) ans += dt[i];
    ans %= 10007;
    printf("%d",ans);
    return 0;
}