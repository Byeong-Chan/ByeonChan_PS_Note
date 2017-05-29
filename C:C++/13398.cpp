#include <cstdio>
int main() {
    int i, n;
    int x, pre, sum;
    int ans = -0x7fffffff;
    int min1 = 0;
    int min2 = 0;
    scanf("%d",&n);
    sum = pre = 0;
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        sum += x;
        if(sum - min1 > ans) ans = sum - min1;
        if(sum - min2 > ans) ans = sum - min2;
        if(min2 > min1 + x) min2 = min1 + x;
        if(min1 > sum) min1 = sum;
    }
    printf("%d\n",ans);
    return 0;
}