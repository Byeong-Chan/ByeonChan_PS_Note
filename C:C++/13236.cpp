#include <cstdio>
int main() {
    int n;
    scanf("%d",&n);
    while(1) {
        printf("%d ",n);
        if(n == 1) break;
        if(n&1) n = (n << 1) + n + 1;
        else n >>= 1;
    }
    printf("\n");
}