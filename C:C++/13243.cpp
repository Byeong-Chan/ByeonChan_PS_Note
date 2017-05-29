#include <cstdio>
int main() {
    int i, n;
    int x;
    int pre = 0;
    long long hap = 0;
    int length = 0;
    int ans = 0;
    long long anssum = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        if(x >= pre) {
            pre = x;
            length++;
            hap += x;
        }
        else {
            pre = x;
            length = 1;
            hap = x;
        }
        if(ans < length) {
            ans = length;
            anssum = hap;
        }
    }
    printf("%d %lld\n",ans,anssum);
    return 0;
}