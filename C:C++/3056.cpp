#include <cstdio>
long double dp[1100000];
long double tp[23][23];
int N;
void comb(int n, int k, int x, int cnt) {
    if (n == 0) {
        int i, pp;
        for(i=0, pp = 1;i<N;i++, pp <<= 1) {
            if (x & pp) continue;
            if (dp[x | pp] < dp[x] * tp[k][i]) dp[x | pp] = dp[x] * tp[k][i];
        }
        return;
    }
    if(cnt < k) comb(n - 1, k, (x << 1) + 1, cnt + 1);
    comb(n - 1, k, x << 1, cnt);
}
int main() {
    int i, j;
    int n;
    int x;
    int f = 0;
    scanf("%d",&n);
    N = n;
    for(i=0;i<n;i++) {
        f <<= 1;
        f++;
    }
    for(i=0;i<n;i++) for(j=0;j<n;j++) {
        scanf("%d",&x);
        if(x != 0) tp[i][j] = (long double)x / 100.0;
        else tp[i][j] = 0;
    }
    dp[0] = 1;
    for(i=0;i<n;i++) comb(n, i, 0, 0);
    printf("%Lf",dp[f] * 100);
    return 0;
}