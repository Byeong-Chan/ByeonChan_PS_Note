#include <cstdio>
int main() {
    int i, n;
    int min1 = 0;
    int x;
    int sum = 0;
    int ans = -0x7fffffff;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        sum += x;
        if (sum - min1 > ans) ans = sum - min1;
        if (min1 > sum) min1 = sum;
    }
    printf("%d\n",ans);
    return 0;
}