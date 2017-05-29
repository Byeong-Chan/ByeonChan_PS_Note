#include <cstdio>
int main() {
    int t;
    int n, m;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        while(m--) scanf("%*d%*d");
        printf("%d\n",n-1);
    }
    return 0;
}