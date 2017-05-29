#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[1010][2];
long long tmp[1010][2];
int pos[1010];
int x[1010];
int main() {
    int i, j;
    int n, pos;
    int st, mid, ed;
    scanf("%d %d",&n, &pos);
    for (i=0;i<n;i++) scanf("%d",&x[i]);
    x[n++] = pos;
    sort(x, x+n);
    for(i=0;i<n;i++) dp[i][0] = dp[i][1] = 0x7fffffff;
    st = 0;
    ed = n-1;
    while (st < ed) {
        mid = (st + ed) >> 1;
        if (x[mid] >= pos) ed = mid;
        else st = mid + 1;
    }
    dp[st][0] = 0;
    dp[st][1] = 0;
    for (i=0;i<n-1;i++) {
        for(j=n-i-1;j>=0;j--) {
            tmp[j][0] = dp[j][0];
            tmp[j][1] = dp[j][1];
            dp[j][0] = 0x7fffffff;
            dp[j][0] <<= 10;
            dp[j][1] = 0x7fffffff;
            dp[j][1] <<= 10;
        }
        for(j=n-i-1;j>=0;j--) {
            if (tmp[j][0] != 0x7fffffff) {
                if (j-1 >= 0) dp[j-1][0] = min(dp[j-1][0], tmp[j][0] + (long long)(x[j] - x[j-1]) * (n - i - 1));
                if (j+i+1 < n) dp[j][1] = min(dp[j][1], tmp[j][0] + (long long)(x[j+i+1] - x[j]) * (n - i - 1));
            }
            if (tmp[j][1] != 0x7fffffff) {
                if (j-1 >= 0) dp[j-1][0] = min(dp[j-1][0], tmp[j][1] + (long long)(x[j+i] - x[j-1]) * (n - i - 1));
                if (j+i+1 < n) dp[j][1] = min(dp[j][1], tmp[j][1] + (long long)(x[j+i+1] - x[j+i]) * (n - i - 1));
            }
        }
    }
    printf ("%lld",min(dp[0][0], dp[0][1]));
    return 0;
}