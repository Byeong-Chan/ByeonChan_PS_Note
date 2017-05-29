#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int i, n, k;
    long long st, ed, mid;
    long long sum;
    long long min1;
    scanf("%d %d",&n,&k);
    st = 1;
    ed = (long long)n * n;
    k--;
    while(st < ed) {
        mid = (st + ed) >> 1;
        sum = 0;
        for(i=1;i<=n;i++) {
            min1 = min((long long)i*n, mid);
            sum += min1 / i;
        }
        if(sum > (long long)k) ed = mid;
        else st = mid + 1;
    }
    printf("%lld",st);
    return 0;
}