#include <cstdio>
int o[1010];
int main() {
    int i, j, n;
    int m1, m2;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    for(i=0;i<=n;i++) {
        m1 = m2 = 0;
        for(j=0;j<n;j++) if(o[j] > i) m1++;
        for(j=0;j<n;j++) if(o[j] == i) m2++;
        if(m1 + m2 >= i && m1 <= i) break;
    }
    printf("%d\n",i);
    return 0;
}