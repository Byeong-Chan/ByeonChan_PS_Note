#include <cstdio>
#include <algorithm>
int o[100010];
void update(int d) {
    while (d > 1) {
        std::swap(o[d>>1], o[d]);
        d>>=1;
    }
}
int main() {
    int i;
    int n;
    int k;
    scanf("%d",&n);
    k = 1;
    for(i=1;i<n;i++) {
        o[i] = ++k;
        update(i);
    }
    o[n] = 1;
    for(i=1;i<=n;i++) printf("%d ",o[i]);
    printf("\n");
    return 0;
}