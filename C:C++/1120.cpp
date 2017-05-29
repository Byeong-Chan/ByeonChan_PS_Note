#include <cstdio>
#include <cstring>
char o[53], u[53];
int main() {
    int i, j;
    int n, m;
    int sum;
    int ans = 0x7ffffff;
    scanf("%s %s",o,u);
    n = (int)strlen(o);
    m = (int)strlen(u);
    for(i=0;i<=m-n;i++) {
        sum = 0;
        for(j=i+n-1;j>=i;j--) if (o[j-i] != u[j]) sum++;
        if (ans > sum) ans = sum;
    }
    printf("%d\n",ans);
    return 0;
}